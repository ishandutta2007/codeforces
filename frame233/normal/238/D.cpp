#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;
char s[N];int pre[N],nxt[N],f[N*11][10],t[N*11],fir[N],A[N*11],B[N*11],st[N*11];
inline void del(int x){pre[nxt[x]]=pre[x],nxt[pre[x]]=nxt[x];}
int main(){
	int n,q;read(n,q);scanf("%s",s+1);
	for(int i=0;i<=n;++i)nxt[i]=i+1,pre[i+1]=i;
	int cur=0,mx=0,id=0;
	while(mx<n){
		cur=mx+1,mx=cur;bool dir=0;
		while(true){
			++id,memcpy(f[id],f[id-1],sizeof(f[id])),t[id]=cur;if(cur==0||cur>n)break;
			if(s[cur]=='<'){
				dir=1,cur=pre[cur];
				if(s[cur]=='<'||s[cur]=='>')del(nxt[cur]);
			}
			else if(s[cur]=='>'){
				dir=0,cur=nxt[cur];
				if(s[cur]=='<'||s[cur]=='>')del(pre[cur]);
			}
			else{
				++f[id][s[cur]-'0'];int o=cur;
				if(dir==0)cur=nxt[cur];else cur=pre[cur];
				if(s[o]=='0')del(o);else --s[o];
			}
			mx=std::max(mx,cur);
		}
	}
	for(int i=1;i<=id;++i)if(!fir[t[i]])fir[t[i]]=i;
	st[0]=id+1;
	for(int i=id,top=0;i>=1;--i){
		while(top&&t[i]>=t[st[top]])--top;
		A[i]=st[top],st[++top]=i;
	}
	for(int i=id,top=0;i>=1;--i){
		while(top&&t[i]<=t[st[top]])--top;
		B[i]=st[top],st[++top]=i;
	}
	while(q--){
		int l,r;read(l,r);int p=std::min(A[fir[r]],B[fir[l]]);
		for(int i=0;i<10;++i)printf("%d%c",f[p-1][i]-f[fir[l]-1][i]," \n"[i==9]);
	}
	return 0;
}