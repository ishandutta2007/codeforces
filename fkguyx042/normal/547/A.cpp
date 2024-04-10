#include<iostream>
#include<stdio.h>
#include<map>
#include<algorithm>
#include<stack>
#include<queue>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<math.h>
#include<fstream>
#include<set>

using namespace std;
typedef long long int ll;
typedef unsigned long long ull;

int main()
{
	ll mod,h1,a1,x1,y1,h2,a2,x2,y2,c1,c2,i,ans=0,temp,j,m1,m2,h11,h12;
	cin>>mod;
	cin>>h1>>a1;
	cin>>x1>>y1;
	cin>>h2>>a2;
	cin>>x2>>y2;
     temp = h2;
     ans = 0;
     h11 = h1;
     h12 = h2;
     for(i=1;i<=mod+10;i++)
	{
	     ans++;
		 h11 = (x1*h11 + y1)%mod;
		 h12 = (x2*h12 + y2)%mod;
		 
		 if(h11==a1 && h12==a2)
		 {
		 	 cout<<ans<<endl;
		 	 return 0;
		 }
	//cout<<h11<<" "<<h12<<endl;	
	} 
	ans = 0;
	for(i=1;i<=mod+10 && h1!=a1;i++)
	{
	     ans++;
		 h1 = (x1*h1 + y1)%mod;
		 h2 = (x2*h2 + y2)%mod;
		// cout<<h1<<" "<<h2<<endl;	
	} 
	//cout<<"------------"<<endl;
	if(h1!=a1)
	{  
	
       cout<<-1<<endl;		
       return 0;
	} 
	if(h1==a1 && h2==a2)
	{
		cout<<ans<<endl;
		return 0;
	}
	
	c1 = 0;
	for(i=1;i<=mod+10 && temp!=a2;i++)
	{
	     c1++;
		 
		 temp = (x2*temp + y2)%mod;	
		 //cout<<temp<<endl;
	} 
	if(temp!=a2)
	{
       cout<<-1<<endl;		
       return 0;
	} 
	 
	ll p,q,r,s;
	p = ans;
	q = c1;
	a1 = h1;
	h1 = (x1*h1 + y1)%mod;

	ans = 1;
	for(i=1;i<=mod+10 && h1!=a1;i++)
	{   
	    ans++;
	  	h1 = (x1*h1 + y1)%mod;
	} 
	if(h1!=a1)
	{
		  //cout<<22<<endl;
		  cout<<-1<<endl;		
         return 0;
	}
	r=ans;
	ans = 1;
	a2 = temp;
	h2 = temp;
	h2 = (x2*h2 + y2)%mod;
//	cout<<a2<<" "<<h2<<endl;
	for(i=1;i<=mod+10 && h2!=a2;i++)
	{   
	    ans++;
	  	h2 = (x2*h2 + y2)%mod;
	  	
	} 
	if(h2!=a2)
	{
		 //cout<<22<<endl;
		 cout<<-1<<endl;		
         return 0;
	}
	s = ans;
	if(p+r==q+s)
	{ 
	    cout<<p+r<<endl;
	    return 0;
	}
	
	for(i=1;i<=mod+10;i++)
	{
		 j = (p-q + r*i)/s;
		 if(p+i*r == q+j*s)
		 {
		 	 //cout<<i<<" "<<p<<" "<<q<<" "<<r<<" "<<s<<" "<<p+i*r<<endl;
		 	 cout<<p+i*r<<endl;
		 	 return 0;
		 }
	}
	
	cout<<-1<<endl;
return 0;	
}