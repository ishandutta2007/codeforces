#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ull unsigned long long
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
ull h[N],cf[N],ans;
char s[N];
int l,fl,sa[N],rak[N],y[N],c[N],js,i,k;
ull GET(int l,int r){return h[r]-h[l-1]*cf[r-l+1];}
/*
sa[i]:il 
rak[i]:i 
sec[i]:i 
*/
int mn[N<<2],tg[N<<2],C[N<<2];
void down(int k){
	if(tg[k]){
		mn[ls]+=tg[k];
		mn[rs]+=tg[k];
		tg[rs]+=tg[k];
		tg[ls]+=tg[k];
		tg[k]=0;
	}
}
void up(int k){
	C[k]=0; 
	if(mn[ls]<=mn[rs])C[k]+=C[ls];
	if(mn[rs]<=mn[ls])C[k]+=C[rs]; 
	mn[k]=min(mn[ls],mn[rs]);
}
void build(int k,int l,int r){
	mn[k]=0;C[k]=(r-l+1);
	if(l==r)return ;
	build(ls,l,mid),build(rs,mid+1,r);
}
int CAL(int k,int l,int r,int x,int y){
	if(fl)return 0;
	if(x<=l&&r<=y){
		if(mn[k]<0){
			if(l==r){
				fl=1;return 0;
			}
			down(k);
			if(mn[ls]<0){
				int ret=CAL(ls,l,mid,x,y);fl=1;
				return ret;
			}
			else{
				int ret=CAL(ls,l,mid,x,y)+CAL(rs,mid+1,r,x,y);fl=1;
				return ret;
			}
		}
		else{
			if(mn[k]==0)return C[k];
			return 0;
		}
	}
	if(x>r||y<l)return 0; 
	down(k);
	return CAL(ls,l,mid,x,y)+CAL(rs,mid+1,r,x,y);
}
void modify(int k,int l,int r,int x,int y,int v){
	if(x<=l&&r<=y){
		mn[k]+=v;tg[k]+=v;return ;
	}
	if(x>r||y<l)return ;
	down(k);
	modify(ls,l,mid,x,y,v);modify(rs,mid+1,r,x,y,v);up(k);
}
int ll[N],L,R,MID;
int main(){
	scanf("%d%s",&l,s+1);
	for(cf[0]=i=1;i<=l;++i){
		rak[i]=s[i]-'('+1;
		h[i]=h[i-1]*23+rak[i];cf[i]=cf[i-1]*23;
		++c[rak[i]];
	}
	for(i=1;i<=1000;++i){
		c[i]+=c[i-1];
	}
	for(i=l;i;--i){
		sa[c[rak[i]]--]=i;
	}
	for(k=1;k<=l;k<<=1){
//		for(i=1;i<=l;++i)cout<<sa[i]<<" ";
//		cout<<"\n";
//		for(i=1;i<=l;++i)cout<<rak[i]<<" ";
//		cout<<"\n";
		js=0;
		for(i=l-k+1;i<=l;++i){
			y[++js]=i;
		}
		for(i=1;i<=l;++i){
			if(sa[i]>k)y[++js]=sa[i]-k; 
		}
		memset(c,0,sizeof(c));
		for(i=1;i<=l;++i){
			++c[rak[i]];
		}
		for(i=1;i<=max(l,1000);++i){
			c[i]+=c[i-1];
		}
		for(i=l;i;--i){
			sa[c[rak[y[i]]]--]=y[i];
		}
		swap(rak,y);
		rak[sa[1]]=js=1;
		for(i=2;i<=l;++i){
			rak[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?js:++js;
		}
		if(js==l)break;
	}
	ll[sa[1]]=0;
	for(i=2;i<=l;++i){
		L=0;R=l-max(sa[i],sa[i-1])+1;
		while(L<R){
			MID=R-(R-L>>1);
			if(GET(sa[i],sa[i]+MID-1)==GET(sa[i-1],sa[i-1]+MID-1))L=MID;
			else R=MID-1;
		}
		ll[sa[i]]=L;
	} 
	build(1,1,l);
	for(i=l;i;--i){
		if(s[i]=='(')modify(1,1,l,i,l,1);
		else modify(1,1,l,i,l,-1);
		fl=0;ans+=CAL(1,1,l,i,l);
		if(ll[i])fl=0,ans-=CAL(1,1,l,i,i+ll[i]-1);
	}
	cout<<ans;
}