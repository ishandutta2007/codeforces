#include<bits/stdc++.h>
using namespace std;
int n,a[100005];long long f[100005][7];

int main(){memset(f, 0x3f3f3f3f, sizeof(f));f[0][1]=0;f[0][2]=0;f[0][3]=0;f[0][4]=0;
	cin>>n;
	string str;
	cin>>str;
	string constr="hard";
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=4;j++){
			if(str[i-1]==constr[j-1]){//, 
				f[i][j]=min(f[i-1][j-1],f[i-1][j]+a[i]);	
			}
			else f[i][j]=f[i-1][j];
		}
	}
	cout<<min(min(f[n][1],f[n][2]),min(f[n][3],f[n][4]))<<endl;
	return 0;
}