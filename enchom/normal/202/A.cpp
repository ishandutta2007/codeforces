#include <iostream>
using namespace std;
char curr[15],maxx[15];
char inp[15],iL;
int cL=0,mL=0;

void PrintOut(char ch[],int len)
{
    int i;
    for (i=1;i<=len;i++)
    cout<<ch[i];
    cout<<endl;
    return;
}

int MIN(int a,int b)
{
    if (a<b)
    return a;
    else
    return b;
}

bool CMP()
{
    int i,endcycle=MIN(cL,mL);
    for (i=1;i<=endcycle;i++)
    {
        if (curr[i]>maxx[i])
        return true;
        else if (curr[i]<maxx[i])
        return false;
    }
    if (cL>mL)
    return true;
    else
    return false;
}



void GetMax(int str,int end)
{
    int i,j;
    int copy=cL,d;
    char maxchar=1;
    for (i=1;i<=cL;i++)
    {
        copy++;
        curr[copy]=curr[cL-i+1];
    }
    
    d=copy;
    copy=cL;
    cL=d;
    if (CMP())
    {
       /// PrintOut(curr,cL);
       /// cout<<"^^^ 1 ^^^"<<endl;
        for (i=1;i<=cL;i++)
        maxx[i]=curr[i];
        mL=cL;
    }
    d=copy;
    copy=cL;
    cL=d;
    
    for (i=str;i<=end;i++)
    {
        if (inp[i]>maxchar)
        maxchar=inp[i];
        for (j=i+1;j<=end;j++)
        {
            if (inp[i]==inp[j])
            {
                cL++;
                curr[cL]=inp[i];
                GetMax(i+1,j-1);
                cL--;
            }
        }
    }
    
    if (maxchar==1)
    return;
    
    copy=cL;
    copy++;
    curr[copy]=maxchar;
    for (i=1;i<=cL;i++)
    {
        copy++;
        curr[copy]=curr[cL-i+1];
    }
    
    d=copy;
    copy=cL;
    cL=d;
    if (CMP())
    {
       /// PrintOut(curr,cL);
        ///cout<<"^^^ 2 ^^^"<<endl;
        for (i=1;i<=cL;i++)
        maxx[i]=curr[i];
        mL=cL;
    }
    d=copy;
    copy=cL;
    cL=d;
    
    return;
}

int main()
{
    string a;
    int i;
    cin>>a;
    for (i=0;i<a.length();i++)
    inp[i+1]=a[i];
    iL=a.length();
    GetMax(1,iL);
    PrintOut(maxx,mL);
    return 0;
}