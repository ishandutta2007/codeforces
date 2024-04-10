#include<bits/stdc++.h>
#define ll long long
#define dd long double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=1e5+5;
int n,a[xx],b[xx];
ll m;
dd p[xx];
//sigma T^0~T^A 
dd ksm(dd a,ll b)
{
	dd ans=1;
	while(b)
	{
		if(b&1)ans*=a;
		a*=a;b>>=1;
	}
	return ans;
}
dd DB(dd T,ll A)
{
	dd ans=0;
	for(int k=0;k<=A;k++)ans+=ksm(T,k);
	return ans;
	return (ksm(T,A+1)-1)/(T-1);
}
dd w[38];//35 
dd get(dd T,ll m)
{
	dd ans=0;
	for(int k=1;k<=m;k++)ans+=k*ksm(T,k-1);
	return ans;
	//sigma_{k=1}^m k T^{k-1}
	w[0]=1;
	for(int i=1;i<=35;i++)
	{
		ll num=(1ll<<(i-1));
		w[i]=w[i-1]+(w[i-1]+num*DB(T,num-1))*ksm(T,num);
	}
	ll num=0;
//	dd ans=0;
	for(int i=0;i<=35;i++)
	{
		if(m>>i&1)
		{
			if(!num)num=(1ll<<i),ans=w[i];
			else 
			{
				ans+=(w[i]+num*DB(T,(1ll<<i)-1))*ksm(T,num);
				num+=(1ll<<i);
			}
		}
	}
	return ans;
}
int id[xx],stk[xx];
#define X(i) (p[i])
#define Y(i) (p[i]*a[i])
dd D(int j,int i){return (Y(j)-Y(i))/(X(j)-X(i));}
struct mat
{
	dd a[3][3];
	mat operator*(const mat&w)const
	{
		mat s;
		memset(s.a,0,sizeof(s.a));
		for(int i=0;i<3;i++)
		{
			for(int k=0;k<3;k++)
			{
				dd re=a[i][k];
				for(int j=0;j<3;j++)
					s.a[i][j]+=re*w.a[k][j];
			}
		}
		return s;
	}
	mat operator+(const mat&w)const
	{
		mat s;
		memset(s.a,0,sizeof(s.a));
		for(int i=0;i<=0;i++)
		{
			for(int k=0;k<3;k++)
			{
				dd re=a[i][k];
				for(int j=0;j<3;j++)
					s.a[i][j]+=re*w.a[k][j];
			}
		}
		return s;
	}
	void print()
	{
		puts("Out the Matrix :");
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)cout<<a[i][j]<<" ";
			puts("");
		}
		puts("");
	}
}zy[38],ans;
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read(),b[i]=read();
		scanf("%Lf",&p[i]);
	}
	dd W=0;
	for(int i=1;i<=n;i++)W=max(W,b[i]*p[i]);
	for(int i=1;i<=n;i++)id[i]=i;
	sort(id+1,id+n+1,[&](int x,int y){return p[x]==p[y]?p[x]*a[x]>p[y]*a[y]:p[x]<p[y];});
	int top=0;
	for(int i=1;i<=n;i++)
	{
		if(p[id[i]]==p[id[i-1]])continue;// 
		while(top>1&&D(id[i],stk[top])>=D(stk[top],stk[top-1]))top--;
		stk[++top]=id[i];
	}
	ll num=0;
	dd f=0;
//	for(int i=1;i<=n;i++)cout<<X(i)<<" "<<Y(i)<<"!!!\n";
	for(int i=1;i<=top;i++)
	{
		if(num==m)break;
		int I=stk[i];
		zy[0]={1-X(I),0,0,X(I),1,0,Y(I),W,1};
		for(int j=1;j<=35;j++)zy[j]=zy[j-1]*zy[j-1];
//		cout<<(Y(stk[i+1])-Y(stk[i]))/(X(stk[top+1])-X(stk[top]))<<"\n";
		
		if(i!=top&&(Y(stk[i+1])-Y(stk[i]))/(X(stk[i+1])-X(stk[i]))>-(-f+W*num))continue;
//		cout<<stk[i]<<" ss "<<stk[i+1]<<" "<<(Y(stk[i+1])-Y(stk[i])/(X(stk[top+1])-X(stk[top])))<<"!!\n";
		ans={f,W*num,1,0,0,0,0,0,0};
		for(int j=35;j>=0;j--)
		{
			if(num+(1ll<<j)>=m)continue;
			mat re=ans;
//			cout<<re.a[0][0]<<" "<<re.a[0][1]<<" "<<re.a[0][2]<<"!!\n";
			re=re+zy[j];
//			cout<<re.a[0][0]<<" "<<re.a[0][1]<<" "<<re.a[0][2]<<"!!\n";
//			cerr<<j<<"!@#ASD\n";
			if(i==top||(Y(stk[i+1])-Y(stk[i]))/(X(stk[i+1])-X(stk[i]))<=-(-re.a[0][0]+re.a[0][1]))ans=re,num+=(1ll<<j);
		}
		num++,ans=ans+zy[0];
		f=ans.a[0][0];
		if(num==m)break;
	}
//	cout<<num<<" "<<f<<"!!\n";
	cout<<fixed<<setprecision(6)<<f<<"\n";
//	dd ans=0;
//	for(int i=1;i<=n;i++)
//	{
//		dd res=0;
//		res+=(a[i]*p[i]+m*W*p[i])*DB(1-p[i],m-1);
//		res-=W*p[i]*get(1-p[i],m);
//		ans=max(ans,res);
//		cout<<i<<" "<<res<<"!!\n";
//	}
//	cout<<fixed<<setprecision(6)<<ans<<"\n";
	pc('1',1);
	return 0;
}