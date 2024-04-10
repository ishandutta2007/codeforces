#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long Int;
typedef double Double;

const Double MINUSINFINITY=-999999999.0;
const Double EPS=0.000000001;

struct func
{
    Int a,b;
};

Double FABS(Double a)
{
    if (a<0.0)
    {
        return 0.0-a;
    }
    else
    {
        return a;
    }
}

bool Equal(Double a,Double b)
{
    Double c=FABS(a-b);

    if (c<EPS)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Double CrossX(func a,func b)
{
    Double ans=(Double)(b.b-a.b) / (Double)(a.a-b.a);

    return ans;
}

struct UpperEnvelope
{
    vector<func> functions;
    vector<Double> effective;

    void Add(const func &A)
    {
        Double cross;

        while(!functions.empty())
        {
            cross=CrossX(functions.back(),A);

            if (cross<effective.back() || Equal(cross,effective.back()))
            {
                effective.pop_back();
                functions.pop_back();
            }
            else
            {
                break;
            }

        }

        if (functions.empty())
        cross=MINUSINFINITY;

        functions.push_back(A);
        effective.push_back(cross);

        return;
    }

    Int GetMaxY(Int x) const
    {
        Double X=(Double)x;
        Int l,r,mid;
        Int best;

        l=0;
        r=functions.size()-1;

        while(l<=r)
        {
            mid=(l+r)/2;

            if ( Equal(effective[mid],X) || X>effective[mid] )
            {
                best=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }

        return functions[best].a*x+functions[best].b;
    }
};

UpperEnvelope UE[101];
Int F;
Int n,m,p;
Int A[100001];
Int cats[100001];
Int S[100001];

int main()
{
    func helper;
    Int i,j;
    Int D;
    Int h,t;

    helper.a=0;
    helper.b=0;
    UE[0].Add(helper);

    scanf("%I64d %I64d %I64d",&m,&n,&p);

    A[1]=0;
    for (i=2;i<=m;i++)
    {
        scanf("%I64d",&D);
        A[i]=A[i-1]+D;
    }

    S[0]=0;
    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&h,&t);

        cats[i]=t-A[h];
    }

    sort(cats+1,cats+1+n);

    for (i=1;i<=n;i++)
    {
        S[i]=S[i-1]+cats[i];
    }

    for (i=1;i<=p;i++)
    {
        helper.a=0;
        helper.b=0;
        UE[i].Add(helper);
        for (j=1;j<=n;j++)
        {
            F=cats[j]*j - S[j] + UE[i-1].GetMaxY(cats[j])*-1;

            helper.a=j; ///-(-j) , since we want lower envelope
            helper.b=0-(S[j]+F); ///since we want lower envelope

            UE[i].Add(helper);
        }
    }

    printf("%I64d\n",F);

    return 0;
}