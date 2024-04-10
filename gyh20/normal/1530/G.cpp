#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,t;
char A[2002],B[2002];
struct node{int x,y;};
inline int kth(char*s,re int x){
	for(re int i=1;i<=n;++i)if(s[i]=='1'&&(!--x))return i;
	return n+1;
}
inline void rev(char*s,re int l,re int r,vector<node>&tmp){
	tmp.push_back((node){l,r});
	reverse(s+l,s+r+1);
}
inline void Get(char*s,vector<node>&tmp){
	re int num=0;
	for(re int i=1;i<=n;++i)num+=s[i]=='1';
	if(num<m||m==0)return;
	if(num==m){
		if(!num)return;
		re int lst=0;
		for(re int i=1;i<=n;++i)if(s[i]=='1')lst=i;
		rev(s,1,lst,tmp);
		re bool ia=1;
		for(re int i=1;i<=n;++i)ia&=A[i]==B[i];
		if(!ia)rev(s,kth(s,1),kth(s,m),tmp);
		return;
	}
	for(re int i=num+1;i>m;--i)rev(s,kth(s,i-m),kth(s,i)-1,tmp);
	if(m&1){
		for(re int i=1;i<=m;++i){
			rev(s,kth(s,2),kth(s,m+1),tmp);
			if(i^m)rev(s,kth(s,1),kth(s,m+1)-1,tmp);
		}
	}
	else{
		for(re int i=1;i<=m/2;++i){
			rev(s,kth(s,1),kth(s,m+1)-1,tmp);
			rev(s,kth(s,1)+1,kth(s,m+1),tmp);
		}
	}
}
int main(){
	t=read();
	while(t--){
		n=read(),m=read();
		scanf("%s%s",A+1,B+1);
		vector<node>ansx,ansy;
		Get(A,ansx),Get(B,ansy);
		re bool ia=1;
		for(re int i=1;i<=n;++i)ia&=A[i]==B[i];
		if(!ia){
			puts("-1");
			continue; 
		}
		printf("%u\n",ansx.size()+ansy.size()),reverse(ansy.begin(),ansy.end());
		for(auto z:ansx)printf("%d %d\n",z.x,z.y);
		for(auto z:ansy)printf("%d %d\n",z.x,z.y);
	}
}