#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int b[n];
    int m[5002];
    for(int i=0;i<5002;i++) m[i]=0;
    int kt=0;
    for(int i=0;i<n;i++)
    {
        if(m[a[i]]==k)
        {
            cout<<"NO";
            return 0;
        }
        m[a[i]]++;
        kt=max(m[a[i]],kt);
        b[i]=m[a[i]];
        if(n-i-1==k-kt)
        {
            i++;
            for(;i<n;i++)
            {
                b[i]=kt+1;
                kt++;
            }
        }
    }
    cout<<"YES\n";
    for(int i=0;i<n;i++) cout<<b[i]<<' ';

	return 0;
}