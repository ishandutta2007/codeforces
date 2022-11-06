#include<bits/stdc++.h>
using namespace std;
char As;
const int Mxdt=100000,B=300;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
char pc(char c,bool opt){
	return (opt||putchar(c)),0;static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (opt||(*p1++=c,p1==p2))&&(fwrite(buf,1,p1-buf,stdout),p1=buf),0;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
void print(int x){
	if(x>9)print(x/10);
	pc(x%10^48,0);
}
void printnum(int x,char c){
	if(x<0)pc('-',0),x=-x;
	print(x);pc(c,0);
}
int n,k,q,x,y,a[200005],b[200005],c[200005],t[200005],ans;char C[10];
int num,BL[200005],id[200005],h[16384],ed,bl[205][200005],H[1005][16384];vector<int>v[200005];
int L[205][1005],R[205][1005],ID[205][1005],top,add[205][1005];
void build(int p){
	++num;++h[t[p]];p=(p-1)%k+1;
	while(p<=n){
		v[num].push_back(p);
		BL[p]=num;id[p]=v[num].size();
		p+=k;
	}
	for(int i=0;i<v[num].size()-1;++i){
		ans-=(t[v[num][i]]==0);
	}
	if(n/k>1000){
		for(int i=0;i<v[num].size()-1;++i){
			bl[num][i]=i/B+1;
			if(!ID[num][bl[num][i]])ID[num][bl[num][i]]=++top;
			++H[ID[num][bl[num][i]]][t[v[num][i]]];
			if(!L[num][bl[num][i]])L[num][bl[num][i]]=i+1;
			R[num][bl[num][i]]=i;
		}
	}
}
void rebuild(int id1,int id2,int l,int r,int val){
	ans+=H[ID[id1][id2]][add[id1][id2]];
	for(int i=L[id1][id2]-1;i<=R[id1][id2];++i){
		--H[ID[id1][id2]][t[v[id1][i]]];
		t[v[id1][i]]^=add[id1][id2];
		if(l<=i&&i<=r)t[v[id1][i]]^=val;
		++H[ID[id1][id2]][t[v[id1][i]]];
	}
	add[id1][id2]=0;
	ans-=H[ID[id1][id2]][add[id1][id2]];
}
void change(int st,int val,int opt){
	if(n/k<=1000){
		if(opt)--h[t[v[BL[st]].back()]];
		for(int i=id[st]-1;i<v[BL[st]].size()-1;++i){
			ans+=(t[v[BL[st]][i]]==0);
			t[v[BL[st]][i]]^=val;
			ans-=(t[v[BL[st]][i]]==0);
		}
		if(opt)t[v[BL[st]].back()]^=val;
		if(opt)++h[t[v[BL[st]].back()]];
	}
	else{
		if(opt)--h[t[v[BL[st]].back()]];
		int l=id[st]-1,r=v[BL[st]].size()-2;
		if(l<=r){
			if(bl[BL[st]][l]==bl[BL[st]][r]){
				rebuild(BL[st],bl[BL[st]][l],l,r,val);
			}
			else{
				rebuild(BL[st],bl[BL[st]][l],l,R[BL[st]][bl[BL[st]][l]],val);
				rebuild(BL[st],bl[BL[st]][r],L[BL[st]][bl[BL[st]][r]]-1,r,val);
				for(int i=bl[BL[st]][l]+1;i<bl[BL[st]][r];++i){
					ans+=H[ID[BL[st]][i]][add[BL[st]][i]];
					add[BL[st]][i]^=val;
					ans-=H[ID[BL[st]][i]][add[BL[st]][i]];
				}
			}	
		}
		if(opt)t[v[BL[st]].back()]^=val;
		if(opt)++h[t[v[BL[st]].back()]];
	}
}
void Change(int x,int v){
	if((n-x+1)%k==0){
		change(x,v,0);
		if(x<n)change(x+1,v,0);
		ed^=v;
	}
	else{
		change(x,v,1);
		if(x<n){
			if(x%k==n%k)change(x+1,v,1);
			else change(x+1,v,0);	
		}
	}
}
char Bt;
int main(){
//	system("fc mission.out mission2.ans");
//	freopen("mission.in","r",stdin);
//	freopen("mission.out","w",stdout);
//	cout<<(&Bt-&As)/1024/1024<<";\n";
	n=read();k=read();q=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	for(int i=1;i<=n;++i)t[i]=c[i]=a[i]^b[i];
	for(int i=1;i<=n-k+1;++i){
		if(t[i])for(int j=i+1;j<i+k;++j)t[j]^=t[i];
	}
	ans=n;for(int i=n-k+1;i<=n;++i)build(i);
	if(h[ed]+(t[n-k+1]!=ed)==k)cout<<ans-h[ed]<<"\n";
	else puts("-1");if(k==1)ans-=h[0];
	for(int i=1;i<=q;++i){
		scanf("%s",C+1);x=read();y=read();
		if(C[1]=='a'){
			if(k==1){
				ans+=(t[x]==0);
				a[x]=y;
				t[x]^=(a[x]^b[x]^c[x]);
				c[x]=a[x]^b[x];
				ans-=(t[x]==0);
			}
			else{
				a[x]=y;
				Change(x,a[x]^b[x]^c[x]);
				c[x]=a[x]^b[x];	
			}
		}
		else{
			if(k==1){
				ans+=(t[x]==0);
				b[x]=y;
				t[x]^=(a[x]^b[x]^c[x]);
				c[x]=a[x]^b[x];
				ans-=(t[x]==0);
			}
			else{
				b[x]=y;
				Change(x,a[x]^b[x]^c[x]);
				c[x]=a[x]^b[x];	
			}
		}
		if(k==1)cout<<ans<<'\n';
		else{
			if(h[ed]+(t[n-k+1]!=ed)==k)cout<<ans-h[ed]<<"\n";
			else puts("-1");	
		}
	}
	return pc(0,1);
}