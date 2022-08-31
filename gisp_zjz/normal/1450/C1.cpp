#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
typedef vector<int>vi;
const int maxn=1e6+100;
const int M=1000000007;
int n,_,tot[3],id;
char s[505][505];
int main(){
    cin >> _;
    while (_--){
        cin >> n;
        memset(tot,0,sizeof(tot));
        for (int i=0;i<n;i++) cin >> s[i];
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                tot[(i+j)%3]+=s[i][j]=='X';
        id=0;
        for (int i=1;i<=2;i++) if (tot[i]<tot[id]) id=i;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if (s[i][j]=='X'&&(i+j)%3==id) s[i][j]='O';
        for (int i=0;i<n;i++) cout << s[i] << endl;
    }
    return 0;
}