#include<iostream>
using namespace std;
int main(){
int h,m,s,t,k,i,j,l=0;
cin>>h>>m>>s>>t>>k;
j=min(t,k);
t=max(t,k);
    if(s>j*5&&s<t*5) l++;
    if(m>=j*5&&m<t*5) l++;
    if(h>=j&&h<t) l++;
if(l<3&&l>0) cout<<"NO";

else cout<<"YES";
return 0;
}