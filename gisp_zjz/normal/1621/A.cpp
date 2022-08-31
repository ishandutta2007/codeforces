#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int M=998244353;
const int maxn=1e6+10;
int n,k,_;
char s[55][55];
int main(){
    cin >> _;
    while (_--){
        cin >> n >> k;
        if (k>(n+1)/2){puts("-1");continue;}
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                s[i][j]='.';
        for (int i=1;i<=k;i++)
            s[i*2-1][i*2-1]='R';
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++) printf("%c",s[i][j]); puts("");
        }
    }
    return 0;
}