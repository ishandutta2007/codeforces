#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;
int main()
{
    Int ax,ay,bx,by,cx,cy;
    Int diffx,diffy;
    Int i;
    Int tdif1,tdif2;
    
    scanf("%I64d %I64d",&ax,&ay);
    scanf("%I64d %I64d",&bx,&by);
    scanf("%I64d %I64d",&cx,&cy);
    
    diffx=bx-ax;
    diffy=by-ay;
    
    for (i=1;i<=32000;i++)
    {
        if (diffx%i==0 && diffy%i==0)
        {
            diffx/=i;
            diffy/=i;
        }
    }
    if (diffx==diffy)
    {
        if (diffx>0)
        {
            diffx=1;
            diffy=1;
        }
        else if (diffy<0)
        {
            diffx=-1;
            diffy=-1;
        }
    }
    if (diffx!=0 || diffy!=0)
    if (diffx*-1==diffy || diffx==diffy*-1)
    {
        if (diffy<0)
        {
            diffy=-1;
            diffx=1;
        }
        else
        {
            diffy=1;
            diffx=-1;
        }
    }
    
    if (diffx==0 && cx==ax)
    {
        if (cy>by>ay || cy<by<ay)
        {
            cout<<"TOWARDS"<<endl;
            return 0;
        }
    }
    if (diffy==0 && cy==ay)
    {
        if (cx>bx>ax || cx<bx<ax)
        {
            cout<<"TOWARDS"<<endl;
            return 0;
        }
    }
    
    if (diffx!=0 && diffy!=0)
    if ( (cx-bx)%diffx==0 && (cy-by)%diffy==0 )
    {
        tdif1=(cx-bx)/diffx;
        tdif2=(cy-by)/diffy;
        
        if (tdif1>=0 && tdif2>=0)
        {
            cout<<"TOWARDS"<<endl;
            return 0;
        }
    }
    
        if (ax<bx)
        {
            if (cy>by)
            {
                cout<<"LEFT"<<endl;
                return 0;
            }
            else
            {
                cout<<"RIGHT"<<endl;
                return 0;
            }
        }
        else if (ax>bx)
        {
            if (cy>by)
            {
                cout<<"RIGHT"<<endl;
                return 0;
            }
            else
            {
                cout<<"LEFT"<<endl;
                return 0;
            }
        }
        else
        {
            if (ay>by)
            {
                if (cx>bx)
                {
                    cout<<"LEFT"<<endl;
                    return 0;
                }
                else
                {
                    cout<<"RIGHT"<<endl;
                    return 0;
                }
            }
            else
            {
                if (cx>bx)
                {
                    cout<<"RIGHT"<<endl;
                    return 0;
                }
                else
                {
                    cout<<"LEFT"<<endl;
                    return 0;
                }
            }
        }
    return 0;
}