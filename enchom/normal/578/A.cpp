#include <iostream>
#include <stdio.h>
using namespace std;
typedef long double Double;

Double MIN(Double a,Double b)
{
    if (a<b)
    return a;
    else
    return b;
}

int MinVal;

Double BestX(int V)
{
    if (V<0)
    return -1.0;
    else if (V==0)
    return (Double)MinVal;

    int GoalValue=V/MinVal;

    if (GoalValue%2==1)
    GoalValue--;

    if (GoalValue==0)
    return -1.0;

    Double TheAns=(Double)V/(Double)GoalValue;

    return TheAns;
}


int main()
{
    int A,B;
    Double ans1,ans2;
    Double ans;

    scanf("%d %d",&A,&B);

    MinVal=B;

    ans1=BestX(A-B);
    ans2=BestX(A+B);

    if (ans1<-0.1)
    ans=ans2;
    else if (ans2<-0.1)
    ans=ans1;
    else
    ans=MIN(ans1,ans2);

    if (ans<-0.1)
    printf("-1\n");
    else
    printf("%.10f\n",(double)ans);

    return 0;
}