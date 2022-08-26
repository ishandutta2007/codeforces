#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
const int maxn=105;
const int M=998244353;
int _,n,m,a[maxn][maxn],b[maxn][maxn],l[maxn],r[maxn];
int main(){
    cin >> _;
    while (_--){
		cin >> n >> m;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				cin >> a[i][j];
		for (int i=1;i<=n;i++) l[i]=1,r[i]=m,sort(a[i]+1,a[i]+m+1);
		for (int i=1;i<=m;i++){
            int pos=1;
            for (int j=1;j<=n;j++) if (a[j][l[j]]<a[pos][l[pos]]) pos=j;
            for (int j=1;j<=n;j++){
				if (j==pos) b[j][i]=a[j][l[j]],l[j]++;
				else b[j][i]=a[j][r[j]],r[j]--;
            }
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++) printf("%d ",b[i][j]);puts("");
		}
    }
    return 0;
}