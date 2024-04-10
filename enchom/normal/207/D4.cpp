#include <iostream>
using namespace std;
char word[100000];
char title[100000];
int tL=0;
int wL=0;

int CHECK(string a)
{
    int L=a.length(),i,j;
    char ch[100000];
    int times=0;
    bool flag=false;
    
    for (i=0;i<L;i++)
    ch[i+1]=a[i];
    
    for (i=1;i<=wL-L;i++)
    {
        flag=false;
        for (j=i;j<=i+L-1;j++)
        {
            if (ch[j-i+1]!=word[j])
            {
                flag=true;
                break;
            }
        }
        if (!flag)
        {
            times++;
        }
    }
    return times;
}

int tCHECK(string a)
{
    int L=a.length(),i,j;
    char ch[100000];
    int times=0;
    bool flag=false;
    
    for (i=0;i<L;i++)
    ch[i+1]=a[i];
    
    for (i=1;i<=tL-L;i++)
    {
        flag=false;
        for (j=i;j<=i+L-1;j++)
        {
            if (ch[j-i+1]!=title[j])
            {
                flag=true;
                break;
            }
        }
        if (!flag)
        {
            times++;
        }
    }
    return times;
}

int main()
{
    int ind,i;
    int financ=0,news=0,trade=0;
    char lame;
    
    cin>>ind;
    cin.get(lame);
    while (1)
    {
        tL++;
        cin.get(title[tL]);
        if (title[tL]==10)
        break;
        if (title[tL]>='A' && title[tL]<='Z')
        title[tL]=title[tL]+('a'-'A');
    }
    while (!cin.eof())
    {
        wL++;
        cin.get(word[wL]);
        if (word[wL]==10)
        {
            word[wL]=' ';
        }
        if (word[wL]>='A' && word[wL]<='Z')
        word[wL]=word[wL]+('a'-'A');
    }
    
    financ+=tCHECK("money fall")*3;
    financ+=tCHECK("loans fall")*3;
    financ+=tCHECK("balance fall")*3;
    trade+=tCHECK("trade")*4;
    trade+=tCHECK("trading")*3;
    trade+=tCHECK("investment")*3;
    news+=tCHECK("news")*3;
    news+=tCHECK("reporter")*3;
    news+=tCHECK("money");
    news+=tCHECK("bank");
    news+=tCHECK("minister")*3;
    news+=tCHECK("chief")*3;
    news+=tCHECK("court")*3;
    news+=tCHECK("white house")*3;
    financ+=tCHECK("finance")*3;
    financ+=tCHECK("balance")*3;
    financ+=tCHECK("money");
    financ+=tCHECK("money supply")*3;
    financ+=tCHECK("bank");
    news+=CHECK("said")*3;
    news+=CHECK("called")*3;
    
    trade+=CHECK("trade")*3;
    trade+=CHECK("trading")*2;
    trade+=CHECK("investment")*2;
    news+=CHECK("news")*2;
    news+=CHECK("reporter")*2;
    news+=CHECK("money");
    news+=CHECK("bank");
    news+=CHECK("minister")*2;
    news+=CHECK("chief")*2;
    news+=CHECK("court")*2;
    news+=CHECK("white house")*2;
    news+=CHECK("he called");
    news+=CHECK("he said");
    news+=CHECK("1)");
    news+=CHECK("2)");
    news+=CHECK("3)");
    news+=CHECK("4)");
    financ+=CHECK("finance")*2;
    financ+=CHECK("balance")*2;
    financ+=CHECK("money");
    financ+=CHECK("money supply")*2;
    financ+=CHECK("money growth")*2;
    financ+=CHECK("money fall")*2;
    financ+=CHECK("loans fall")*2;
    financ+=CHECK("balance fall")*2;
    financ+=CHECK("bank");
    
    if (news>=financ && news>=trade)
    cout<<1<<endl;
    else if (financ>=news && financ>=trade)
    cout<<2<<endl;
    else
    cout<<3<<endl;
    return 0;
}