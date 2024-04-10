#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

char g[200200];
int n,t,p, m = 200100,f=0;
vector<int> a;

void arred(int pos) {
    int carry = 0;
    if(g[pos] - '0' >= 5) {
        g[pos] = '$';

        carry = 1;
        for(int i=pos-1; i >= 0; i--) {
            if(g[i] == '9') {
                g[i] = '0';
                carry = 1;
            }
            else if(g[i] != '.'){
                g[i] += carry;
                carry = 0;
                break;
            }
        }
    }
    else {
        g[pos] = '$';
    }

    if(carry) {
        f = 1;
        m = 0;
    }

    t--;
    m = min(m,pos);
    //printf("%s\n",g);
}

int main() {
    scanf("%d %d %s", &n, &t, g);

    for(p=0;p<n;p++)
        if(g[p] == '.')
            break;

    for(int i=p+1;i<n;i++) {
        if(g[i] == '$') break;
        if(g[i] - '0' >= 5 && t && i <= m) arred(i);
        else if(g[i] == '4' && t && i <= m) {
            a.push_back(i);
        }
    }

    while(!a.empty() && t) {
        int id = a.back();
        if(g[id] - '0' >= 5 && id <= m) arred(id);
        a.pop_back();
    }

    if(f) printf("1");
    for(int i=0;i<n;i++) {
        if(g[i] == '$') break;
        if(g[i] != '.') printf("%c",g[i]);
        if(g[i] == '.') {
            if(g[i+1] != '$' && g[i] != '0') printf("%c",g[i]);
            else break;
        }
    }
    printf("\n");
    return 0;
}