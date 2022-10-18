#include <iostream>

using namespace std;

int main()
{
    int n,max_capacity=0,cur=0,a,b;
    cin>>n;
    while(n--){
        cin>>a>>b;
        cur+=b-a;
        if(cur>max_capacity)max_capacity=cur;
    }
    cout<<max_capacity;
    return 0;
}