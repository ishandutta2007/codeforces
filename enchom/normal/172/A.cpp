#include <iostream>
using namespace std;

string phones[300001];

int main()
{
    int n;
    int i,j;
    int longest=0;
    bool correct;
    
    cin>>n;
    
    for (i=1;i<=n;i++)
    cin>>phones[i];
    
    for (i=0;i<phones[1].length();i++)
    {
        correct=true;
        for (j=1;j<=n-1;j++)
        {
            if (phones[j][i]!=phones[j+1][i])
            {
                correct=false;
                break;
            }
        }
        if (correct)
        {
            longest++;
        }
        else
        break;
    }
    cout<<longest<<endl;
    return 0;
}