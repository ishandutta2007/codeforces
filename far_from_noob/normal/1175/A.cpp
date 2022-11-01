#include <bits/stdc++.h>
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)
#define pb puch_back

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
    ll n,k;
    cin>>n>>k;
    ll count=0;
    if(k==1){cout<<n<<endl;return 0;}
    while(1){
        if(n%k==0){n=n/k;count++;}
        else {
            count+=n%k;
            n= k * (n/k);

        }
        //count=count+1;
        if(n==0)break;
    }
    cout<<count<<" ";
    }

    return 0;
}