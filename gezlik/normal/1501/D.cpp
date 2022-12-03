#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=500000;

int n,m,a[N+9],b[N+9],p[N*2+9];
LL sk,g,len;

void into(){
  scanf("%d%d%lld",&n,&m,&sk);
  len=1LL*n*m/(g=__gcd(n,m));
  for (int i=0;i<n;++i)
	scanf("%d",&a[i]);
  for (int i=0;i<m;++i)
	scanf("%d",&b[i]);
  if (n<m) swap(n,m),swap(a,b);
}

void Get_p(){
  for (int i=0;i<=n<<1;++i) p[i]=-1;
  for (int i=0;i<m;++i) p[b[i]]=i;
}

int c[N*2+9];

void Get_c(){
  for (int i=0;i<n;++i)
	if (p[a[i]]^-1) ++c[i<p[a[i]]?i-p[a[i]]+n:i-p[a[i]]];
}

bool Check_mid(LL mid){
  LL t=mid,cnt=t/len,res=cnt*c[0];
  int now=0;
  for (now=m%n,t-=cnt*m;now;now=(now+m)%n,t-=cnt*m) res+=1LL*cnt*c[now];
  for (;2333;now=(now+m)%n,t-=m){
	if (t<m){
	  for (int j=0;t;--t,now=(now+1)%n,++j) res+=b[j]==a[now];
	  break;
	}
	res+=c[now];
  }
  return mid-res>=sk;
}

LL ans;

void Two_divide_ans(){
  LL l=0,r=(1LL<<60)-1;ans=r+1;
  for (LL mid;l<=r;Check_mid(mid=l+r>>1)?(ans=mid,r=mid-1):l=mid+1);
}

void work(){
  Get_p();
  Get_c();
  Two_divide_ans();
}

void outo(){
  printf("%lld\n",ans);
}

int main(){
  into();
  work();
  outo();
  return 0;
}