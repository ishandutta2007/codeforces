#include <iostream>
using namespace std;

typedef long long Int;

bool Prime(Int a)
{
    Int i;
    for (i=2;i*i<=a;i++)
    {
        if (a%i==0)
        return false;
    }
    return true;
}

int main()
{
    string a;
    Int i,k;
    Int reverse;
    Int nth=0,d;
    
    cin>>d;
    
    for (i=2;i<=1000000;i++)
    {
        reverse=0;
        if (Prime(i))
        {
            k=i;
            while (k>0)
            {
                reverse=reverse*10+k%10;
                k=k/10;
            } 
            k=k/10;
            if (Prime(reverse) && reverse!=i)
            {
                nth++;
                if (nth==d)
                {
                    cout<<i<<endl;
                    return 0;
                }
            }
        }
    }
    
}