#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int N = 1e7 + 10;
int T;
char s[N];
int n;
vector<pair<pair<int, int>, int> > d;
void Lyndon_depress(char * s, int n) {
    int i = 0;
    int id = 0;
    d.clear();
    while (i < n) {
        int j = i + 1, k = i;
        while (j < n && s[j] >= s[k]) {
            if (s[j] > s[k])
                k = i;
            else
                k ++;
            j ++;
        }
        ++id;
        if (j - k == 1) {
            while (i <= k) {
                d.push_back(make_pair(make_pair(i, 1), id));
                i ++;
            }
        } else {
            int len = 0;
            d.push_back(make_pair(make_pair(i, 0), id));
            while (i <= k) {
                len += j - k;
                i += j - k;
            }
            d[d.size() - 1].first.second = len;
        }
    }
}
#include <string>
char s1[N], ss1[N];
int Next[N], Extend[N];
void add(vector<string>&d, string a, string b) {
    d.push_back(a+ b);
    reverse(a.begin(), a.end());
    d.push_back(a+b);
    reverse(b.begin(), b.end());
    d.push_back(a+b);
    reverse(a.begin(), a.end());
    d.push_back(a+b);
}

void getNext(char s[], int Next[], int n) {
    Next[0] = n;
    Next[1] = 0;
    while (s[1 + Next[1]] == s[Next[1]]) Next[1] ++;
    int x = 1;
    for (int i = 2; i < n ; i ++)
        if (Next[i - x] + i < Next[x] + x) {
            Next[i] = Next[i - x];
        } else {
            Next[i] = max(Next[x] + x - i, 0);
            while (s[Next[i]] == s[Next[i] + i]) Next[i]  ++;
            if (Next[i] + i >  Next[x] + x) x = i;
        }
}
void getExtend(char as[], char bs[], int Next[], int Extend[], int na, int nb) {
    getNext(as, Next, na);
    Extend[0] = 0;
    while (Extend[0] < na && Extend[0] < nb && as[Extend[0]] == bs[Extend[0]]) Extend[0] ++;
    int x = 0;
    for (int i = 1; i < nb; i ++)
        if (Next[i - x] + i < Extend[x] + x) {
            Extend[i] = Next[i - x];
        } else {
            Extend[i] = max(Extend[x] + x - i, 0);
            while (Extend[i] + i < nb && Extend[i] < na && as[Extend[i]] == bs[Extend[i] + i]) Extend[i]++;
            if (Extend[i] + i > Extend[x] + x) x = i;
        }
}
void did(int l, int r, bool sig) {
    if (sig) {
        int n = 0;
        for (int i = l; i <= r; i ++)
            s1[n ++] = s[i];
        s1[n] = 255;
        int nn = 0;
        for (int i = r; i >= l; i --)
            ss1[nn ++] = s[i];
        ss1[n] = 255;
        getExtend(s1, ss1, Next, Extend, n, n);
        Lyndon_depress(s1, n);
        reverse(d.begin(), d.end());
        if (d[0].second == d[d.size() - 1].second) {
            int len = r- l + 1;
            bool sig = 1;
            for (int i = 0; i < len ; i ++)
                if (s[l + i] != s[r - i]){
                    sig = (s[l + i] < s[r - i]);
                    break;
                }
            if (sig)
                for (int i = 0; i < len ; i ++)
                    printf("%c", s[i + l]);
            else
                for (int i = 0; i < len ; i ++)
                    printf("%c", s[r - i]);
        } else {
            string s2 = "";
            int i = 0;
            while (d[i].second == d[0].second) {
                for (int j = 0; j < d[i].first.second; j ++)
                    s2 += s1[j + d[i].first.first];
                i ++;
            }
            string s3 = "";
            int tmp = d[i].second;
            while (i < d.size() && d[i].second == tmp) {
                for (int j = 0; j < d[i].first.second; j ++)
                    s3 += s1[j + d[i].first.first];
                i ++;
            }
            vector<string> w;
            int len = s2.length() + s3.length();
            string s4 = "";
            for (int i = 0; i <  n - len; i ++)
                s4 += s1[i];
            add(w, s2, s4 + s3);
            add(w, s3 + s2, s4);
            add(w, s4 + s3 + s2, string(""));
            int best = 0;
            for (int i = 1; i < n - 1; i ++)
                if (Extend[best] + best - 1 < i - 1) {
                    if (ss1[Extend[best] + best] < s1[Extend[best]]) best = i;
                } else
                {
                    if (Next[i - best] + i - best < n - best && s1[Next[i - best]] < s1[Next[i - best] + i - best])
                        best = i;
                }
            string s5 = "";
            for (int i = 0; i < best; i ++)
                s5 += ss1[i];
            for (int i = n - 1; i >= best; i --)
                s5 += ss1[i];
            w.push_back(s5);
            sort(w.begin(), w.end());
            printf("%s", w[0].c_str());
        }
    } else {
        int len = r- l + 1;
        bool sig = 1;
        for (int i = 0; i < len ; i ++)
            if (s[l + i] != s[r - i]){
                sig = (s[l + i] < s[r - i]);
                break;
            }
        if (sig)
            for (int i = 0; i < len ; i ++)
                printf("%c", s[i + l]);
        else
            for (int i = 0; i < len ; i ++)
                printf("%c", s[r - i]);
    }
}
int main() {
    int k;
    scanf("%s", s);
    scanf("%d", &k);
    n = strlen(s);
    reverse(s, s + n);
    Lyndon_depress(s, n);
    reverse(d.begin(), d.end());
    bool last = 0;
    for (auto u:d) {
            if (k == 2 && !last) {
                did(0, u.first.first + u.first.second - 1, 1);
                break;
            }
            if (u.first.second == 1) {
                if (last) {
                    printf("%c", s[u.first.first]);
                }else
                if (k == 1){
                    did(0, u.first.first + u.first.second - 1, 0);
                    break;
                } else {
                    k --;
                    last = 1;
                    printf("%c", s[u.first.first]);
                }
            }else {
                if (k == 2) {
                    did(0, u.first.first + u.first.second - 1, 1);
                    break;
                }
                if (k > 1) {
                    for (int i = 0; i < u.first.second; i++)
                        printf("%c", s[u.first.first + i]);
                    k--;
                } else {
                    did(0, u.first.first + u.first.second - 1, 0);
                    break;
                }
                last = 0;
            }
    }
    puts("");
    return 0;
}