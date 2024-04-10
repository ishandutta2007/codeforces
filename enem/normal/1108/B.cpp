#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int n;
    cin>>n;
    int d[n],m[n];
    int a=1,b=1;
    for(int i=0;i<n;i++)
    {
        cin>>d[i];
        if(d[i]>a) a=d[i];
        m[i]=0;
    }
    sort(d,d+n);
    for(int i=0;i<n;i++)
    {
        if(a%d[i]==0)
        {
            m[i]=1;
            if(d[i]==d[i+1]) i++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(m[i]==0)
        {
            if(d[i]>b) b=d[i];
        }
    }
    cout<<a<<' '<<b;

	return 0;
}