#include <bits/stdc++.h>
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)
#define pb puch_back
ll ko=(ll)pow(2,32);

using namespace std;

int main()
{
    ll n,x=0,flag=0;
    cin>>n;
    string s;
    ll p[n],temp=0;
    p[0]=1;
    //int x=0;
    while(n--){
        cin>>s;
        if(s[0]=='a'){
            if(x>=ko-p[temp] && flag==0){cout<<"OVERFLOW!!!";
            flag=1;
            }
            x+=p[temp];
        }
        if(s[0]=='f'){
                temp++;
            cin>>p[temp];
            p[temp]*=p[temp-1];
            if(p[temp]>=ko){p[temp]=ko;
            }
            //t=t*p;
        }
        if(s[0]=='e')temp--;

    }
    if(flag==0)
    cout<<x;

    return 0;
}