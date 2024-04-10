#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
int mod=998244353;
int main(){
	int n;
	scanf("%d",&n);
	int a[100005];
	for(int i = 0;i<n;i++)
		scanf("%d",&a[i]);
	char b[100005];
	scanf("%s",b);
	int l=-1e9,r=1e9;
	for(int i = 4;i<n;i++){
		if(b[i-4]==b[i-3]&&b[i-3]==b[i-2]&&b[i-2]==b[i-1]){
			if(b[i-1]=='0'){
				if(b[i]=='0'){

				}
				else{
					for(int j = 0;j<5;j++)
					l=max(l,a[i-j]+1);
				}
			}
			else{
				if(b[i]=='1'){

				}
				else{
					for(int j =0;j<5;j++)
					r=min(r,a[i-j]-1);
				}
			}
		}
	}
	printf("%d %d\n",l,r);
}