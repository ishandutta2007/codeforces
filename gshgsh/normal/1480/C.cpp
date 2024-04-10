#include<iostream>
using namespace std;
#define MAXN 100001
int N,a[MAXN];
int main(){cin>>N;int l=1,r=N;while(l<r){int mid=l+r>>1;cout<<"? "<<mid<<endl;cin>>a[mid];cout<<"? "<<mid+1<<endl;cin>>a[mid+1];a[mid]<a[mid+1]?r=mid:l=mid+1;}cout<<"! "<<l<<endl;return 0;}