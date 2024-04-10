#include <iostream>
using namespace std;
int main()
{
    string s1;
    char a[31];
    int n;
    int i,j,in;
    int num1,num2,num3;
    int themaxscore=-1;
    
    cin>>s1;
    n=s1.length();
    
    for (i=0;i<n;i++)
    {
        a[i+1]=s1[i];
    }
    
    for (i=1;i<=n-2;i++)
    {
        for (j=i+1;j<=n-1;j++)
        {
            if (a[1]=='0' && i>1)
            break;
            
            if (a[i+1]=='0' && j>i+1)
            continue;
            
            if (a[j+1]=='0' && j<n-1)
            continue;
            
            num1=0;
            num2=0;
            num3=0;
            for (in=1;in<=i;in++)
            {
                num1=num1*10+( a[in]-'0' );
            }
            if (i>7)
            continue;
            for (in=i+1;in<=j;in++)
            {
                num2=num2*10+( a[in]-'0' );
            }
            if (j-(i+1)+1>7)
            continue;
            for (in=j+1;in<=n;in++)
            {
                num3=num3*10+( a[in]-'0' );
            }
            if (n-(j+1)+1>7)
            continue;
            
            if (num1>1000000 || num2>1000000 || num3>1000000)
            continue;
            
            if (num1+num2+num3>themaxscore)
            themaxscore=num1+num2+num3;
        }
    }
    cout<<themaxscore<<endl;
    return 0;
}