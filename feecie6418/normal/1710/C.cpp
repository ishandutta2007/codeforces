#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,f[200005][8][8][8],v[200005];
char a[200005];
void upd(int &x,int y){
	x+=y,(x>=mod&&(x-=mod));
}
int main(){
	cin>>a+1;
	n=strlen(a+1),a[n+1]='0';
	reverse(a+1,a+n+1);
	for(int i=1;i<=n+1;i++)v[i]=a[i]-'0';
	f[0][0][7][7]=1;
	for(int i=0;i<n+1;i++){
		for(int j=0;j<8;j++){
			for(int k=0;k<8;k++){
				for(int l=0;l<8;l++){
					int val=f[i][j][k][l];
					if(!val)continue;
					for(int t=0;t<8;t++){
						int z=(t>>2),y=(t>>1)%2,x=t%2;
						int nl=((x==v[i+1]?(l&1):((x>v[i+1])?0:1))|(y==v[i+1]?(l&2):((y>v[i+1])?0:2))|(z==v[i+1]?(l&4):((z>v[i+1])?0:4)));
						int p=(x^y),q=(y^z),r=(z^x);
						int xp=(p+q+(j&1)),xq=(q+r+((j>>1)&1)),xr=(r+p+(j>>2));
						int nj=(xp>>1)+((xq>>1)<<1)+((xr>>1)<<2);
						int vp=(xp&1),vq=(xq&1),vr=(xr&1);
						int nk=((vp==r?(k&1):((vp>r)?0:1))|(vq==p?(k&2):((vq>p)?0:2))|(vr==q?(k&4):((vr>q)?0:4)));
						upd(f[i+1][nj][nk][nl],val);
					}
				}
			}
		}
	}
	cout<<f[n+1][0][0][7];
}