#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;
const int MX = 10010;

using namespace std;

int n;
int l[N];
int r[N];
char c[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        r[i] = i + 1;
    for(int i = 1; i <= n; i++)
        l[i] = i - 1;
    l[1] = n;
    r[n] = 1;
    int vta = 0,
        vtb = 0,
        sa = 0,
        sb = 0;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        if(c[i] == 'D')
            sa++;
        else
            sb++;
    }
    int x = 1;
    while(sa && sb){
        if(c[x] == 'D'){
            if(vtb){
                sa--;
                vtb--;
                int L = l[x],
                    R = r[x];
                r[L] = R;
                l[R] = L;
                x = r[x];
                continue;
            }
            vta++;
        }
        else{
            if(vta){
                sb--;
                vta--;
                int L = l[x],
                    R = r[x];
                r[L] = R;
                l[R] = L;
                x = r[x];
                continue;
            }
            vtb++;
        }
        x = r[x];
    }
    if(sa)
        cout << 'D' << endl;
    else
        cout << 'R' << endl;
}