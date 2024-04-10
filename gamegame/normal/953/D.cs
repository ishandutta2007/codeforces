using System;
using System.Text;
class Program
{
    static int[,] a = new int[6,8] {{3,3,0,4,4,0,3,3},{3,3,0,4,4,0,3,3},{2,2,0,3,3,0,2,2},{2,2,0,3,3,0,2,2},{1,1,0,2,2,0,1,1},{1,1,0,2,2,0,1,1}};
    static int maxi=-1,x,y;
    static string[] op = new string[6];
    static void Main()
    {
        string str;
        for (var i = 0; i < 6; ++i)
        { 
            str = Console.ReadLine();
            op[i]=str;
            for(var j=0; j<8 ;++j){
                if(str[j]=='.' && a[i,j]>maxi){
                    maxi=a[i,j];
                    x=i;
                    y=j;
                }
            }
        }
        StringBuilder sb = new StringBuilder(op[x]);
        sb[y] = 'P';
        op[x]=sb.ToString();
        for (var i = 0; i < 6; ++i)
        { 
            Console.WriteLine(op[i]);
        }

    }
    
}