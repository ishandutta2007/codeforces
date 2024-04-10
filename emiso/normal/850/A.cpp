
#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a[MN][6], bad[MN], b, c, d;
queue<int> s;
vector<int> ans;
//char s[MN]; string str;

int scalar(int i, int j, int p) {
    return (a[i][0] - a[p][0])*(a[j][0] - a[p][0])
            + (a[i][1] - a[p][1])*(a[j][1] - a[p][1])
            + (a[i][2] - a[p][2])*(a[j][2] - a[p][2])
            + (a[i][3] - a[p][3])*(a[j][3] - a[p][3])
            + (a[i][4] - a[p][4])*(a[j][4] - a[p][4]);
}

int main() {
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<5; j++) {
            scanf("%d",&a[i][j]);
            s.push(i);
        }
    }

    while(!s.empty()) {
        if(s.size() > 2) {
            b = s.front(); s.pop();
            c = s.front(); s.pop();
            d = s.front(); s.pop();

            if(scalar(d, b, c) <= 0) {
                bad[d] = 1;
                bad[b] = 1;
                s.push(c);
            }

            else if(scalar(d, c, b) <= 0) {
                bad[d] = 1;
                bad[c] = 1;
                s.push(b);
            }

            else if(scalar(b, c, d) <= 0) {
                bad[b] = 1;
                bad[c] = 1;
                s.push(d);
            }

            else {
                bad[d] = 1;
                bad[b] = 1;
                bad[c] = 1;
            }
        }

        else {
            b = s.front(); s.pop();
            int flag = 1;

            for(int i = 0; i < n && flag; i++) {
                if(i == b) continue;
                for(int j = 0; j < n && flag; j++) {
                    if(j == b || j == i) continue;
                    if(scalar(i, j, b) > 0) flag = 0;
                }
            }

            if(flag) ans.push_back(b);
            else bad[b] = 1;
        }
    }

    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for(int x : ans) {
        printf("%d\n", x + 1);
    }
    return 0;
}