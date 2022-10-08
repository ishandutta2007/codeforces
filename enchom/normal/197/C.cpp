#include <iostream>
using namespace std;

int seq[100001],sL;
int contain[27];
char answer[100001];
int aL=0;

int main()
{
    string k;
    int i,uk=26;
    
    cin>>k;
    
    for (i=0;i<=26;i++)
    contain[i]=0;
    for (i=0;i<k.length();i++)
    {
        seq[i+1]=(int)(k[i]-'a');
        contain[seq[i+1]]++;
    }
    sL=k.length();
    for (i=1;i<=sL;i++)
    {
        while (1)
        {
            if (uk==-1)
            break;
            
            if (contain[uk]==0)
            uk--;
            else
            break;
        }
        if (uk==-1)
        break;
        
        if (seq[i]==uk)
        {
            aL++;
            answer[aL]=(char)(uk+'a');
        }
        contain[seq[i]]--;
    }
    for (i=1;i<=aL;i++)
    cout<<answer[i];
    cout<<endl;
    return 0;
}