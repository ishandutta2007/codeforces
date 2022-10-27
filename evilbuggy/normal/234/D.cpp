#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int mini[105], maxi[105];
bool fav[105];

int main(){

// #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
// #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    memset(fav, false, sizeof(fav));
    int m, k, x;
    cin>>m>>k;

    for(int i = 0; i < k; i++){
        cin>>x;
        fav[x] = true;
    }
    string s;
    int n, d;
    cin>>n;
    int maxima = 0, minima = 0;
    for(int i = 1; i <= n; i++){
        cin>>s>>d;
        int fcnt = 0, nfcnt = 0, vacnt = 0;
        while(d--){
            cin>>x;
            if(x == 0)vacnt++;
            else if(fav[x])fcnt++;
            else nfcnt++;
        }
        maxi[i] = fcnt + min(k - fcnt, vacnt);
        mini[i] = fcnt + max(vacnt - m + k + nfcnt, 0);
        maxima = max(maxima, maxi[i]);
        minima = max(minima, mini[i]);
        // cout<<maxi[i]<<" "<<mini[i]<<" "<<fcnt<<" "<<nfcnt<<" "<<vacnt<<endl;
    }
    for(int i = 1; i <= n; i++){
        bool pos = true;
        for(int j = 1; j <= n; j++){
            if(i == j || mini[i] >= maxi[j])continue;
            pos = false;
            break;
        }
        if(pos){
            cout<<0<<endl;
        }else if(maxi[i] >= minima){
            cout<<2<<endl;
        }else{
            cout<<1<<endl;
        }
    }
}