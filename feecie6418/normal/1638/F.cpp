#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10005],ans=0,b[10005],s1[10005],s2[10005],sufmx[10005];
int top,st[10005],fl[10005],fr[10005],n,t1,t2;
int T,S[10005],m,tl[10005];
ll Get(){
	S[T=0]=0;
	ll mx=0;
	for(int i=1;i<=m;i++){
		while(T&&b[S[T]]>=b[i])T--;
		tl[i]=S[T]+1,S[++T]=i;
	}
	S[T=0]=m+1;
	for(int i=m;i;i--){
		while(T&&b[S[T]]>=b[i])T--;
		mx=max(mx,(S[T]-tl[i])*b[i]);
		S[++T]=i;
	}
	return mx;
}
void Ss(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)b[j]=min(a[j],a[i]);
		t1=t2=0;
		ll curmn=1e13;
		for(int j=i;j>=1;j--){
			//s1 
			if(b[j]<=curmn)s1[++t1]=j,curmn=b[j];
		}
		s1[++t1]=0,curmn=1e13;
		for(int j=i;j<=n;j++){
			//s2 
			if(b[j]<=curmn)s2[++t2]=j,curmn=b[j];
		}
		s2[++t2]=n+1,sufmx[t2]=0;
		int L=i,R=i;
		while(L>1&&b[L-1]>=b[i])L--;
		while(R<n&&b[R+1]>=b[i])R++;
		for(int i=t2-1;i>=1;i--){
			sufmx[i]=max(sufmx[i+1],(s2[i+1]-L)*b[s2[i]]);
		}
		for(int j=t1-1,kkk=0;j>=1;j--){
			while(kkk+1<t2&&b[s2[kkk+1]]+b[s1[j]]>=a[i])kkk++;
			int lj=s1[j+1]+1,rj=R;
			int ljj=L,rjj=s2[kkk+1]-1;
			ans=max(ans,(rj-lj+1)*b[s1[j]]+max((rjj-ljj+1)*(a[i]-b[s1[j]]),sufmx[kkk+1]));
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		while(top&&a[st[top]]>=a[i])top--;
		fl[i]=st[top]+1,st[++top]=i;
	}
	st[top=0]=n+1;
	for(int i=n;i;i--){
		while(top&&a[st[top]]>=a[i])top--;
		fr[i]=st[top]-1,st[++top]=i;
	}
	for(int i=1;i<n;i++){
		ll m1=0,m2=0;
		for(int j=1;j<=i;j++)m1=max(m1,a[j]*(min(fr[j],i)-fl[j]+1));
		for(int j=i+1;j<=n;j++)m2=max(m2,a[j]*(fr[j]-max(fl[j],i+1)+1));
		ans=max(ans,m1+m2);
	}
	for(int i=1;i<=n;i++){
		m=fr[i]-fl[i]+1;
		for(int j=fl[i];j<=fr[i];j++)b[j-fl[i]+1]=a[j]-a[i];
		ans=max(ans,a[i]*m+Get());
	}
	Ss();
	reverse(a+1,a+n+1);
	Ss();
	cout<<ans;
}