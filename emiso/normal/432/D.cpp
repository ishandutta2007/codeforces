#include <bits/stdc++.h>
#define N 200100

using namespace std;

int z[N];
vector<int> vec;
char s[N];

void z_function(string &str, int *z) {
    for(int i = 1, L = 0, R = 0, sz = str.size(); i < sz; i++) {
        if(i > R) {
            L = R = i;
            while(R < sz && str[R] == str[R - L]) R++;
            z[i] = R - L; R--;
        }
        else {
            if(z[i - L] < R - i + 1) z[i] = z[i - L];
            else {
                L = i;
                while(R < sz && str[R] == str[R - L]) R++;
                z[i] = R - L; R--;
            }
        }
    }
}

struct suffix {
    int index;
    int rank_[2];
} suffixes[N];

int ind[N], suffixArr[N], lcp[N], invSuff[N];
int cmp(struct suffix a, struct suffix b) {
    if (a.rank_[0] == b.rank_[0])
        return a.rank_[1] < b.rank_[1];
    return a.rank_[0] < b.rank_[0];
}

void buildSuffixArray(string txt, int n) {
    for (int i = 0; i < n; i++) {
        suffixes[i].index = i;
        suffixes[i].rank_[0] = txt[i];
        suffixes[i].rank_[1] = ((i+1) < n)? (txt[i + 1]): -1;
    }

    sort(suffixes, suffixes+n, cmp);
    for (int k = 4; k < 2*n; k = k*2) {
        int rank_ = 0;
        int prev_rank_ = suffixes[0].rank_[0];
        suffixes[0].rank_[0] = rank_;
        ind[suffixes[0].index] = 0;

        for (int i = 1; i < n; i++) {
            if (suffixes[i].rank_[0] == prev_rank_ && suffixes[i].rank_[1] == suffixes[i-1].rank_[1]) {
                prev_rank_ = suffixes[i].rank_[0];
                suffixes[i].rank_[0] = rank_;
            }
            else {
                prev_rank_ = suffixes[i].rank_[0];
                suffixes[i].rank_[0] = ++rank_;
            }
            ind[suffixes[i].index] = i;
        }

        for (int i = 0; i < n; i++) {
            int nextindex = suffixes[i].index + k/2;
            suffixes[i].rank_[1] = (nextindex < n)?
            suffixes[ind[nextindex]].rank_[0]: -1;
        }
        sort(suffixes, suffixes+n, cmp);
    }

    for (int i = 0; i < n; i++)
        suffixArr[i] = suffixes[i].index;
}

int countOccurrences(string &pat, string &str) {
    int l = 0, r = str.size();
    for(int i = 0; i < pat.size(); i++) {
        int tl = l, tr = r;
        while(tl < tr) {
            int m = (tl + tr) / 2;
            int idx = suffixArr[m];

            if((idx + i) >= str.size() || str[idx + i] < pat[i])
                tl = m + 1;
            else tr = m;
        }
        l = tl;

        tr = r;
        while(tl < tr) {
            int m = (tl + tr) / 2;
            int idx = suffixArr[m];

            if((idx + i) >= str.size() || str[idx + i] <= pat[i])
                tl = m + 1;
            else tr = m;
        }
        r = tr;

        vec.push_back(r - l);
    }
}


int main() {
    string str;
    scanf("%s", s); str = s;
    buildSuffixArray(str, str.size());
    z_function(str, z); z[0] = str.size();
    countOccurrences(str, str);

    vector<int> ret;
    for(int i = 0; i < str.size(); i++) {
        if(i + z[i] == str.size()) ret.push_back(z[i] - 1);
    } reverse(ret.begin(), ret.end());

    printf("%d\n", ret.size());
    for(int i = 0; i < ret.size(); i++) {
        printf("%d %d\n", ret[i] + 1, vec[ret[i]]);
    }
}