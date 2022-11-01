#include <bits/stdc++.h>

using namespace std;

void dark()
{
    int n,a,b;
    cin>>n>>a>>b;
    if(abs(a-b)>1||a+b >=n-1){
        cout<<-1;
        return;
    }
    int aa[n];
    for(int i=0;i<n;i++){
        aa[i]=i+1;
    }
    if(a>b){
        reverse(aa,aa+n);
        for(int i=0;i<a;i++){
            swap(aa[2*i],aa[(2*i)+1]);
        }
    }
    if(b>a){
        for(int i=0;i<b;i++){
            swap(aa[2*i],aa[(2*i)+1]);
        }
    }
    if(b==a&&b!=0){
        for(int i=0;i<b;i++){
            swap(aa[2*i],aa[(2*i)+1]);
        }
        swap(aa[n-1],aa[n-2]);
    }
    for(int i=0;i<n;i++){
        cout<<aa[i]<<" ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        dark();
        cout<<"\n";
    }
    return 0;
}