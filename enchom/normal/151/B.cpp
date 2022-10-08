#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long Int;

struct bro
{
    Int dacars,dafood,dagirls;
    Int nameL;
    char name[101];
};

bro bros[101];

int main()
{
    Int n;
    Int i,j;
    Int numbers;
    string fname,phone;
    Int maxtaxi=-1,maxpizza=-1,maxgirls=-1;
    bool first;
    
    scanf("%I64d",&n);
    
    for (i=0;i<=100;i++)
    {
        bros[i].dacars=0;
        bros[i].dafood=0;
        bros[i].dagirls=0;
        bros[i].nameL=0;
    }
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&numbers);
        cin>>fname;
        for (j=0;j<fname.length();j++)
        {
            bros[i].name[j+1]=fname[j];
        }
        bros[i].nameL=fname.length();
        
        for (j=1;j<=numbers;j++)
        {
            cin>>phone;
            
            if (phone[0]==phone[1] && phone[1]==phone[3] && phone[3]==phone[4] && phone[4]==phone[6] && phone[6]==phone[7])
            {
                bros[i].dacars++;
            }
            else if (phone[1]<phone[0] && phone[3]<phone[1] && phone[4]<phone[3] && phone[6]<phone[4] && phone[7]<phone[6])
            {
                bros[i].dafood++;
            }
            else
            {
                bros[i].dagirls++;
            }
        }
        if (bros[i].dagirls>maxgirls)
        maxgirls=bros[i].dagirls;
        
        if (bros[i].dafood>maxpizza)
        maxpizza=bros[i].dafood;
        
        if (bros[i].dacars>maxtaxi)
        maxtaxi=bros[i].dacars;
    }
    printf("If you want to call a taxi, you should call: ");
    first=true;
    for (i=1;i<=n;i++)
    {
        if (bros[i].dacars==maxtaxi)
        {
            if (first)
            {
                first=false;
            }
            else
            {
                printf(", ");
            }
            for (j=1;j<=bros[i].nameL;j++)
            printf("%c",bros[i].name[j]);
        }
    }
    printf(".\n");
    
    
    printf("If you want to order a pizza, you should call: ");
    first=true;
    for (i=1;i<=n;i++)
    {
        if (bros[i].dafood==maxpizza)
        {
            if (first)
            {
                first=false;
            }
            else
            {
                printf(", ");
            }
            for (j=1;j<=bros[i].nameL;j++)
            printf("%c",bros[i].name[j]);
        }
    }
    printf(".\n");
    
    
    printf("If you want to go to a cafe with a wonderful girl, you should call: ");
    first=true;
    for (i=1;i<=n;i++)
    {
        if (bros[i].dagirls==maxgirls)
        {
            if (first)
            {
                first=false;
            }
            else
            {
                printf(", ");
            }
            for (j=1;j<=bros[i].nameL;j++)
            printf("%c",bros[i].name[j]);
        }
    }
    printf(".\n");
    
    return 0;
}