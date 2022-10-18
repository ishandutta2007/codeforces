#include <iostream>

using namespace std;

int n,a[4],cur=0,t;

int main()
{
    cin>>n;
    while(n--){
        cin>>t;
        a[cur]+=t;
        cur = (cur+1)%3;
    }
    if(a[0]>a[1]&&a[0]>a[2])cout<<"chest";
    if(a[1]>a[0]&&a[1]>a[2])cout<<"biceps";
    if(a[2]>a[0]&&a[2]>a[1])cout<<"back";
    return 0;
}