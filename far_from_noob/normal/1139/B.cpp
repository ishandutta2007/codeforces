#include <iostream>

using namespace std;

int main()
{
    long long  n,countans=0,temp;
    cin >>n;
    long long  a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        //if((a[i]-'0')%2==0)
        //countans+=i+1;
    }
    temp=a[n-1];
    countans=temp;
    for(int i=n-2;i>=0;i--){
        if(a[i]<temp)
        {
            countans+=a[i];
            temp=a[i];
        }
        else if(temp > 0){
            temp=temp-1;
            countans+=temp;
        }
        else{
            temp=0;
        }


    }


    cout<< countans;


    return 0;
}