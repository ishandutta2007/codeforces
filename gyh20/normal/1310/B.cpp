#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=(1<<16)+5;
int a[MAXN][3];
int main() {
int n,k,x;
cin>>n>>k;
memset(a,-0x3f,sizeof(a));//-1044266559
for(int i=1; i<=k; i++) {
scanf("%d",&x);
x=(x+1)>>1;
if(a[x][0]==1) {
a[x][0]=a[x][1]=-1044266559;
a[x][2]=1;
} else a[x][0]=a[x][1]=1;
}
for(k=n-1; k; k--) {
for(int i=1; i<=(1<<k); i+=2) {
int tmp[3]= {-1044266559,-1044266559,-1044266559};
tmp[0]=max(tmp[0],a[i][0]+a[i+1][0]+2);
tmp[2]=max(tmp[2],a[i][0]+a[i+1][1]+3);
tmp[2]=max(tmp[2],a[i][0]+a[i+1][2]+3);
tmp[2]=max(tmp[2],a[i][1]+a[i+1][0]+3);
tmp[2]=max(tmp[2],a[i][1]+a[i+1][1]+2);
tmp[2]=max(tmp[2],a[i][1]+a[i+1][2]+3);
tmp[2]=max(tmp[2],a[i][2]+a[i+1][0]+3);
tmp[2]=max(tmp[2],a[i][2]+a[i+1][1]+3);
tmp[2]=max(tmp[2],a[i][2]+a[i+1][2]+3);
tmp[0]=max(tmp[0],max(a[i][0],a[i+1][0])+2);
tmp[0]=max(tmp[0],max(a[i][1],a[i+1][1])+2);
tmp[1]=max(tmp[1],max(a[i][1],a[i+1][1])+1);
tmp[2]=max(tmp[2],max(a[i][2],a[i+1][2])+3);
a[(i>>1)+1][0]=tmp[0];
a[(i>>1)+1][1]=tmp[1];
a[(i>>1)+1][2]=tmp[2];
}
}
cout<<max(max(0,a[1][0]+1),max(a[1][1]+1,a[1][2]+1));
return 0;
}