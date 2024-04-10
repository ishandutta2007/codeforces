#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

double ABS(double a)
{
    if (a<0.0)
    return a*-1.0;
    else
    return a;
}

int main()
{
    double x1,y1,r1;
    double x2,y2,r2;
    double side1,side2,answer;
    ///4 0 201
    ///-6 4 279
    cin>>x1>>y1>>r1;
    cin>>x2>>y2>>r2;
    side1=ABS(x1-x2);
    side2=ABS(y1-y2);
    answer=sqrt(side1*side1+side2*side2);
    
    if (r1<answer && r2<answer)
    {
        answer=answer-r1-r2;
        if (answer<0)
        answer=0.0;
        answer=answer/2;
    }
    else
    {
        if (r1>=answer && r1>=r2)
        {
            if (answer+r2>=r1)
            {
                answer=0.0;
            }
            else
            {
                answer=(r1-answer-r2)/2;
            }
        }
        else
        {
            if (answer+r1>=r2)
            {
                answer=0.0;
            }
            else
            {
                answer=(r2-answer-r1)/2;
            }
        }
    }
    
    
    printf("%4.7f",answer);
    return 0;
}