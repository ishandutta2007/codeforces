#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
const int maxn=600;
const int M=998244353;
int n,a[maxn],b[maxn][maxn];
int main(){
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	memset(b,-1,sizeof(b));
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			b[i][j]=0;
    for (int i=1;i<=n;i++){
		int x=i,y=i;
		b[x][y]=a[i];
		for (int j=1;j<a[i];j++){
			if (!b[x][y-1]) y--; else x++;
			b[x][y]=a[i];
		}
    }
    for (int i=1;i<=n;i++){
		for (int j=1;j<=i;j++) printf("%d ",b[i][j]); puts("");
    }
    return 0;
}