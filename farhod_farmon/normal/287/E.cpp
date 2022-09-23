#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1000010;

using namespace std;

int n, q, a[N], s[N], l, v[N];

int main()
{
	//fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    //sc("%d", &n);
    cin >> n;
    for(int i = 1; i <= n; i++){
        //sc("%d", &a[i]);
        cin >> a[i];
        s[i] = 1;
    }
    //sc("%d", &q);
    cin >> q;
    for(int i = 1; i <= q; i++){
        int x;
        //sc("%d", &x);
        cin >> x;
        s[x] = -1;
    }
    for(int i = n; i >= 1; i--){
        if(l == 0 || s[i] == -1){
            v[++l] = -a[i];
            s[i] = -1;
            continue;
        }
        if(v[l] == -a[i])
            l--;
        else{
            s[i] = -1;
            v[++l] = -a[i];
        }
    }
    if(l){
        //pr("NO\n");
        cout << "NO\n";
        return 0;
    }
    //pr("YES\n");
    cout << "YES\n";
    for(int i = 1; i <= n; i++)
        //pr("%d ", a[i] * s[i]);
        cout << a[i] * s[i] << " ";
}