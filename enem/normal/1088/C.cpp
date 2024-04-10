#include <bits/stdc++.h>
using namespace std;
/*{{ x | (1 << k) sets the kth bit of x to one
x & ~(1 << k) sets the kth bit of x to zero
x ^ (1 << k) inverts the kth bit of x.
x & (x1) sets the last one bit of x to zero
x & x sets all the one bits to zero, except for the last one bit. 
x | (x1) inverts all the bits after the last one bit.}} SOME BIT MANIPULATION*/
//__builtin_clz(x): the number of zeros at the beginning of the number
//__builtin_ctz(x): the number of zeros at the end of the number
//__builtin_popcount(x): the number of ones in the number
//__builtin_parity(x): the parity (even or odd) of the number of ones
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define INF 1e18
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i<=b; i++)
void build(ll v,ll tl,ll tr,ll st[],ll lz[],bool f[],ll a[])
{
    if(tl==tr)
    {
        st[v]=a[tl];
        lz[v]=0LL;
        f[v]=false;
        return;
    }
    build((v<<1),tl,((tl+tr)>>1),st,lz,f,a);
    build((v<<1)|1,((tl+tr)>>1)+1,tr,st,lz,f,a);
    //operation
    st[v]=st[(v<<1)]+st[(v<<1)|1];
    lz[v]=0LL;
    f[v]=false;
    return;
}
 
void push(ll v,ll tl,ll tr,ll st[],ll lz[],bool f[])
{
    if(f[v])
    {
        //operation
        st[(v<<1)]=lz[(v<<1)]=st[(v<<1)|1]=lz[(v<<1)|1]=0LL;
        f[(v<<1)]=f[(v<<1)|1]=true;
        f[v]=false;
    }
    //operation
    st[(v<<1)]+=lz[v]*(((tl+tr)>>1)-tl+1);
    //operation
    lz[(v<<1)]+=lz[v];
    //operation
    st[(v<<1)|1]+=lz[v]*(tr-((tl+tr)>>1));
    //operation
    lz[(v<<1)|1]+=lz[v];
    lz[v]=0LL;
    return;
}
 
void update(ll v,ll tl,ll tr,ll l,ll r,ll val,bool set,ll st[],ll lz[],bool f[])
{
    if(l>r)
    {
        return;
    }
    if(l==tl&&tr==r)
    {
        if(set)
        {
            //operation
            st[v]=lz[v]=0LL;
            f[v]=true;
        }
        //operation
        st[v]+=val*(tr-tl+1);
        //operation
        lz[v]+=val;
        return;
    }
    push(v,tl,tr,st,lz,f);
    update((v<<1),tl,((tl+tr)>>1),l,min(r,((tl+tr)>>1)),val,set,st,lz,f);
    update((v<<1)|1,((tl+tr)>>1)+1,tr,max(l,((tl+tr)>>1)+1),r,val,set,st,lz,f);
    //operation
    st[v]=st[(v<<1)]+st[(v<<1)|1];
    return;
}
 
ll query(ll v,ll tl,ll tr,ll l,ll r,ll st[],ll lz[],bool f[])
{
    if(l>r)
    {
        return 0LL;
    }
    if(l==tl&&tr==r)
    {
        return st[v];
    }
    push(v,tl,tr,st,lz,f);
    //operation
    return query((v<<1),tl,((tl+tr)>>1),l,min(r,((tl+tr)>>1)),st,lz,f)+query((v<<1)|1,((tl+tr)>>1)+1,tr,max(l,((tl+tr)>>1)+1),r,st,lz,f);
}
int power(int k)
{
    int temp=1;
    REP(i,0,k-1)
    {
        temp=temp*10;
    }
    return temp;
}
bool compare(const pair<int,int>&a, const pair<int,int>&b)
{
    return a.S<b.S;
}
 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	int max=0;
	REP(i,0,n-1)
	{
		cin>>a[i];
		if(max<a[i])
		{
		    max=a[i];
		}
	}
    max=500000;
	int flag=1;
	REP(i,0,n-2)
	{
	    if(a[i]>=a[i+1])
	    {
	        flag=0;
	        break;
	    }
	}
	if(flag==1)
	{
	    cout<<0;
	}
	else
	{
	int temp=max+2;
	int temp1=max+1;
	vector<pair<int,int>> p;
	for(int i=n-1;i>=0; i--)
	{
		int temp2=(temp1-a[i])%temp;
		if(temp2<0)
		{
		    temp2=temp2+temp;   
		}
		if(temp2==0)
		{
		    temp1--;
		    continue;
		}
		else
		{
		p.PB(MP(i,temp2));
		{
			for(int j=i; j>=0; j--)
			{
				a[j]=a[j]+temp2;
			}
		}
		}
		temp1--;
	}
    cout<<p.size()+1<<'\n';
	for(int i=0; i<=p.size()-1; i++)
	{
		cout<<1<<" "<<p[i].F+1<<" "<<p[i].S<<endl;
	}
	cout<<2<<" "<<n<<" "<<temp;
	}
}