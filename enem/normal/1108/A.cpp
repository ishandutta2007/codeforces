#include <iostream>
using namespace std;


int main() {
	int t;
    cin>>t;
    while(t--)
    {
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        int a=l1,b=l2;
        if(a==b)
        {
            if(a<r1) a++;
            else b++;
        }
        cout<<a<<' '<<b<<'\n';
    }
	return 0;
}