#include <iostream>
#include <stdio.h>
using namespace std;

struct function
{
    char name[12];
    int nameL,parameters,param[6];
};

struct variable
{
    char name[12];
    int nameL,vartype;
};

function func[1001];
variable var[1001];


bool Same(char arr1[],int L1,char arr2[],int L2)
{
    if (L1!=L2)
    return false;
    
    int i;
    for (i=1;i<=L1;i++)
    {
        if (arr1[i]!=arr2[i])
        return false;
    }
    return true;
}

int main()
{
    int n,m,k;
    int i,j,in;
    char line[102];
    int L=0;
    char type[10];
    char procedureName[12];
    char currparam[12];
    int cpL=0;
    int procparam[6],ppL=0;
    int pnL=0;
    int tL=0;
    char input;
    int ans;
    bool out;
    
    
    scanf("%d",&n);
    scanf("%c",&input);
    for (i=1;i<=n;i++)
    {
        L=0;
        while(1)
        {
            scanf("%c",&input);
            if ( (int)input==10 )
            break;
            if (input!=' ')
            {
                L++;
                line[L]=input;
            }
        }
        j=5;
        func[i].nameL=0;
        while (line[j]!='(')
        {
            func[i].nameL++;
            func[i].name[func[i].nameL]=line[j];
            j++;
        }
        tL=0;
        j++;
        for (j;j<=L;j++)
        {
            if (line[j]==',' || line[j]==')')
            {
                if (tL==1)
                {
                    func[i].parameters++;
                    func[i].param[ func[i].parameters ]=0;
                }
                else if (tL==3)
                {
                    func[i].parameters++;
                    func[i].param[ func[i].parameters ]=1;
                }
                else if (tL==6)
                {
                    if (type[1]=='d')
                    {
                        func[i].parameters++;
                        func[i].param[ func[i].parameters ]=2;
                    }
                    else
                    {
                        func[i].parameters++;
                        func[i].param[ func[i].parameters ]=3;
                    }
                }
                tL=0;
                if (line[j]==')')
                break;
            }
            else
            {
                tL++;
                type[tL]=line[j];
            }
        }
    }
    
    
    scanf("%d",&m);
    scanf("%c",&input);
    for (i=1;i<=m;i++)
    {
        L=0;
        while(1)
        {
            scanf("%c",&input);
            if ( (int)input==10 )
            break;
            if (input!=' ')
            {
                L++;
                line[L]=input;
            }
        }
        var[i].nameL=0;
        if (line[1]=='i')
        {
            var[i].vartype=1;
            for (j=4;j<=L;j++)
            {
                var[i].nameL++;
                var[i].name[var[i].nameL]=line[j];
            }
        }
        else if (line[1]=='d')
        {
            var[i].vartype=2;
            for (j=7;j<=L;j++)
            {
                var[i].nameL++;
                var[i].name[var[i].nameL]=line[j];
            }
        }
        else if (line[1]=='s')
        {
            var[i].vartype=3;
            for (j=7;j<=L;j++)
            {
                var[i].nameL++;
                var[i].name[var[i].nameL]=line[j];
            }
        }
    }
    
    scanf("%d",&k);
    scanf("%c",&input);
    for (i=1;i<=k;i++)
    {
        L=0;
        ppL=0;
        while(1)
        {
            scanf("%c",&input);
            if ( (int)input==10 )
            break;
            if ( input!=' ' )
            {
                L++;
                line[L]=input;
            }
        }
        pnL=0;
        j=1;
        while (line[j]!='(')
        {
            pnL++;
            procedureName[pnL]=line[j];
            j++;
        }
        j++;
        for (j;j<=L;j++)
        {
            if (line[j]==',' || line[j]==')')
            {
                for (in=1;in<=m;in++)
                {
                    if (Same(currparam,cpL,var[in].name,var[in].nameL))
                    {
                        ppL++;
                        procparam[ppL]=var[in].vartype;
                        break;
                    }
                }
                cpL=0;
                if (line[j]==')')
                break;
            }
            else
            {
                cpL++;
                currparam[cpL]=line[j];
            }
        }
        ans=0;
        for (j=1;j<=n;j++)
        {
            if (func[j].parameters!=ppL)
            continue;
            
            if (Same(procedureName,pnL,func[j].name,func[j].nameL))
            {
                out=true;
                for (in=1;in<=ppL;in++)
                {
                    if (procparam[in]!=func[j].param[in] && func[j].param[in]!=0)
                    {
                        out=false;
                        break;
                    }
                }
                if (!out)
                continue;
                else
                {
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}