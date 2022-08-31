#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,x,y;
    cin>>n>>x>>y;
    int k=0;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<=x) k++;
    }
    if(x>y) cout<<n;
    else cout<<(k+1)/2;
	return 0;
}