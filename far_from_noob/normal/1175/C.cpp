#include <bits/stdc++.h>
#define flo long long
#define floa double
#define fo(i,n) for(int i=0;i<n;i++)
#define pb puch_back
//ll o=(ll)pow(2,32);
//map<float,float>ko;

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
            map<floa,flo>ko;
        int n,k;
        cin>>n>>k;
        floa a[n];
        fo(i,n)cin>>a[i];
        sort(a,a+n);
        floa p[n];
        for(int i=0;i<n-k;i++){
            p[i]=abs(a[i+k]-a[i])/2;
            ko[abs(a[i+k]-a[i])/2]=abs(a[i+k]+a[i])/2;
        }
        sort(p,p+n-k);
        //printf("%.lf",ko[p[0]]);
        cout<<ko[p[0]]<<endl;
    }

    return 0;
}