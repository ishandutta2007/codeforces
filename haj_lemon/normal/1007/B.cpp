#include<bits/stdc++.h>
#define ll long long
using namespace std;
int x,y,z,t,xy,yz,xz,xyz,f[100010];
ll ansn,c[12];
int gcd(int x,int y){if (x%y==0) return y;return gcd(y,x%y);}
ll c2(ll x){return x*(x+1)/2;}
ll c1(ll x){return (x+2)*(x+1)*(x)/6;}
bool p3(int x){return ((x==1)|(x==2)|(x==4));}
int main(){
	for (int i=1;i<=100000;i++)
		for (int j=i;j<=100000;j+=i)f[j]++;
	scanf("%d",&t);
	while (t--){
		scanf("%d %d %d",&x,&y,&z);ansn=0;
		xy=gcd(x,y);xz=gcd(x,z);yz=gcd(y,z);xyz=gcd(xy,z);
		c[1]=f[x]-f[xy]-f[xz]+f[xyz];
		c[2]=f[y]-f[xy]-f[yz]+f[xyz];
		c[3]=f[xy]-f[xyz];
		c[4]=f[z]-f[xz]-f[yz]+f[xyz];
		c[5]=f[xz]-f[xyz];
		c[6]=f[yz]-f[xyz];
		c[7]=f[xyz];
		for (int i=1;i<=7;i++){
			for (int j=i;j<=7;j++){
				for (int k=j;k<=7;k++){
					if ((i|j|k)==7){
						if (p3(i|j)||p3(i|k)||p3(j|k))continue;
						if (i==j&&j==k)ansn=ansn+c1(c[i]);
						if (i!=j&&j!=k)ansn=ansn+c[i]*c[j]*c[k];
						if (i==j&&j!=k)ansn=ansn+c2(c[i])*c[k];
						if (i!=j&&j==k)ansn=ansn+c2(c[j])*c[i];
					}
				}
			}
		}
		cout<<ansn<<endl;
	}
	return 0;
}
/*
1
18 66 9
*/