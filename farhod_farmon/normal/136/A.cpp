#include <iostream>
using namespace std;
int main()
{
int i,k,a[105],n;
cin>>n;
for(i=1;i<=n;i++){
cin>>k;
a[k]=i;
}
for(i=1;i<=n;i++){
cout<<a[i]<<" ";
}
}