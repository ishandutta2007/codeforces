#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    Int TUX;
    Int FOO,BAR,BAZ,QUZ;
    Int PUR;
    double ans;
    
    cin>>TUX;
    
    FOO=0;
    BAR=0;
    BAZ=0;
    QUZ=1;
    
    while(TUX!=0)
    {
        cin>>PUR;
        FOO=FOO+PUR;
        BAR=BAR+1;
        
        if (FOO*QUZ>=BAR*BAZ)
        {
            BAZ=FOO;
            QUZ=BAR;
        }
        
        TUX--;
    }
    
    ans=(double)BAZ/(double)QUZ;
    
    printf("%.4f\n",ans);
    
    return 0;
}