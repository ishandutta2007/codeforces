#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int t,n;
char s[60];
inline void orz(bool p=0)
{
    int i,j,k;
    if(!s[n])
      {
       if(!s[1])
         cout<<"? "<<(s+2)<<"O\n";
       else
         cout<<"? "<<(s+1)<<"O\n";
       fflush(stdout);
       cin>>k;
       while(k--)
         {
          scanf("%d",&i);
          s[i+n-1-(!s[1])]='O';
         }
       if(!s[n])
         s[n]='H';
      }
    if(!s[1] && p)
      {
       cout<<"? H"<<(s+2)<<"\n";
       fflush(stdout);
       cin>>k;
       while(k--)
         {
          scanf("%d",&i);
          s[i]='H';
         }
      }
    if(!s[1])
      {
       cout<<"? O"<<(s+2)<<"\n";
       fflush(stdout);
       cin>>k;
       while(k--)
         {
          scanf("%d",&i);
          s[i]='O';
         }
       if(!s[1])
         s[1]='C';
      }
       cout<<"! "<<(s+1)<<"\n";
       fflush(stdout);
       cin>>k;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	cin>>t;
	while(t--)
	  {
       cin>>n;
       for(i=1;i<=n+1;i++)
         s[i]=0;
       cout<<"? CC\n";
       fflush(stdout);
       cin>>k;
       while(k--)
         {
          scanf("%d",&i);
          s[i]='C';
          s[i+1]='C';
         }
       cout<<"? OC\n";
       fflush(stdout);
       cin>>k;
       while(k--)
         {
          scanf("%d",&i);
          s[i]='O';
          s[i+1]='C';
         }
       cout<<"? HC\n";
       fflush(stdout);
       cin>>k;
       while(k--)
         {
          scanf("%d",&i);
          s[i]='H';
          s[i+1]='C';
         }
       cout<<"? HO\n";
       fflush(stdout);
       cin>>k;
       while(k--)
         {
          scanf("%d",&i);
          s[i]='H';
          s[i+1]='O';
         }
       if(n==4 && !s[1] && !s[4] && s[2] && s[3])
         {
          orz(1);
          continue;
         }
       cout<<"? HH\n";
       fflush(stdout);
       cin>>k;
       while(k--)
         {
          scanf("%d",&i);
          s[i]='H';
          s[i+1]='H';
         }
       for(i=2;i<n;i++)
         if(!s[i])
           s[i]='O';
       if(n==4 && !s[1] && !s[4] && s[2] && s[3])
         {
       cout<<"? OOO\n";
       fflush(stdout);
       cin>>k;
       while(k--)
         {
          scanf("%d",&i);
          s[i]='O';
          s[i+1]='O';
          s[i+2]='O';
         }
       if(!s[1])
         s[1]='C';
       if(!s[4])
         s[4]='H';
       cout<<"! "<<(s+1)<<"\n";
       fflush(stdout);
       cin>>k;
       continue;
         }
       orz();
      }
	return 0;
}