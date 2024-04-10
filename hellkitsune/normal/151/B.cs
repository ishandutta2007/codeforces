using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int n;
            string[] best = new string[3];
            int[] bestcount = { 0, 0, 0 };
            n = int.Parse(Console.ReadLine());
            for (int i = 0; i < 3; i++)
                best[i] = "";
            for (int i = 0; i < n; i++)
            {
                string[] t = Console.ReadLine().Split(
                    new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
                int k = int.Parse(t[0]);
                string name = t[1];
                int a = 0, b = 0, c = 0;
                for (int j = 0; j < k; j++)
                {
                    string[] s = Console.ReadLine().Split(
                        new char[] {' ', '\t', '-' }, StringSplitOptions.RemoveEmptyEntries);
                    int n1 = int.Parse(s[0]);
                    int n2 = int.Parse(s[1]);
                    int n3 = int.Parse(s[2]);
                    if ((n1 == n2) && (n2 == n3) && (n1 / 10 == n1 % 10))
                    {
                        a++;
                    }
                    else
                    {
                        if ((n1 % 10 < n1 / 10) &&
                            (n2 / 10 < n1 % 10) &&
                            (n2 % 10 < n2 / 10) &&
                            (n3 / 10 < n2 % 10) &&
                            (n3 % 10 < n3 / 10))
                            b++;
                        else
                            c++;
                    }
                }
                if (a == bestcount[0])
                {
                    if (string.Compare(best[0], "") == 0)
                        best[0] = name;
                    else
                        best[0] = best[0] + ", " + name;
                }
                if (b == bestcount[1])
                {
                    if (string.Compare(best[1], "") == 0)
                        best[1] = name;
                    else
                        best[1] = best[1] + ", " + name;
                }
                if (c == bestcount[2])
                {
                    if (string.Compare(best[2], "") == 0)
                        best[2] = name;
                    else
                        best[2] = best[2] + ", " + name;
                }
                if (a > bestcount[0])
                {
                    bestcount[0] = a;
                    best[0] = name;
                }
                if (b > bestcount[1])
                {
                    bestcount[1] = b;
                    best[1] = name;
                }
                if (c > bestcount[2])
                {
                    bestcount[2] = c;
                    best[2] = name;
                }
            }
            Console.WriteLine("If you want to call a taxi, you should call: " + best[0] + ".");
            Console.WriteLine("If you want to order a pizza, you should call: " + best[1] + ".");
            Console.WriteLine("If you want to go to a cafe with a wonderful girl, you should call: " + best[2] + ".");
        }
    }
}