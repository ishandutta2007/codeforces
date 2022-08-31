#include<cstdio>
#include<unordered_map>
using namespace std;
unordered_map<int,int>m[100002];
int f[100002],s[100002],p[100002],cnt,z,n;
inline int read(){
	int t=0;char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int main(){
	n=read();
    for(int i=1;i<=n;++i){
        int v=read(),c=read(),l=read(),r=read();
        if(r+c<100001&&(!l||m[l].find(r+c)!=m[l].end())){
            int u=m[l][r+c];
            f[i]=f[u]+v,p[i]=u;
            if(!r&&f[i]>f[z])z=i;
            if(f[i]>f[m[l+c][r]])m[l+c][r]=i;
        }
    }
    while(z)s[++cnt]=z,z=p[z];
    printf("%d\n",cnt);
    while(cnt)printf("%d ",s[cnt--]);
}