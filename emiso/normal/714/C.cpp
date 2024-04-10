#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;

struct Trie {
    vector <Trie*>  m;
    int integers;

    Trie() : integers(0), m(2) {}

    void insert(string s,int pos) {
        int t = s[pos] - '0';

        if(pos < 0) {
            return;
        }

        if(m[t] == NULL) {
            m[t] = new Trie();
            m[t]->integers = 0;
        }
        m[t]->insert(s,pos-1);
        m[t]->integers++;
    }

    void rem(string s,int pos) {
        int t = s[pos] - '0';

        if(pos < 0) {
            return;
        }

        m[t]->rem(s,pos-1);
        m[t]->integers--;
    }

    int query(string s,int pos) {
        int t = s[pos] - '0';

        if(pos < 0) {
            return integers;
        }

        if(m[t] == NULL) return 0;

        return (m[t]->query(s,pos-1));
    }
};

int main() {
    int n;
    char x[20], t;
    long long y;

    scanf("%d",&n);

    Trie dic;

    for(int i=0; i<n; i++) {
        scanf(" %c",&t);
        string str;

        if(t == '?') {
            scanf(" %s",x);
            str = x;
            while(str.size() < 18) str = '0' + str;
            printf("%d\n",dic.query(str, 17));
        }

        else {
            scanf(" %lld", &y);

            string b = "";
            for(int i=0; i<18; i++) {
                if(y % 2 == 0) b = "0" + b;
                else b = "1" + b;
                y /= 10;
            }

            if(t == '-') dic.rem(b, 17);
            if(t == '+') dic.insert(b, 17);
        }
    }

    return 0;
}