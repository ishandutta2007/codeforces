#include <iostream>
using namespace std;

int main() {
    long long n,m,count=0;
    cin >> n >>m;
    int a[m+1];
    for(int i=0;i<m;i++)
    {
        cin >> a[i+1];
    }
    a[0]=1;
    for(int i=0;i<m;i++)
    {
        if(a[i]==a[i+1])
        continue;
        if(a[i]>a[i+1])
        {
            count+=n-(a[i]-a[i+1]);
        }
        else
        count+=(long long)a[i+1]-a[i];
    }
    cout<< count;
    
    
	return 0;
}