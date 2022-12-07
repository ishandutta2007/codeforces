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
            string[] t = Console.ReadLine().Split(
                new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
            Int64 a = Int64.Parse(t[0]);
            if (a < 4)
            {
                Console.Write("1\n0");
                return;
            }
            for (Int64 i = 2; i <= Math.Sqrt(a) + 2; i++)
            {
                if (a % i == 0)
                {
                    a = a / i;
                    if (a == 1)
                    {
                        Console.Write("1\n0");
                        return;
                    }
                    if (a < 4)
                    {
                        Console.Write("2");
                        return;
                    }
                    else
                    {
                        for (Int64 j = i; j <= Math.Sqrt(a) + 2; j++)
                            if (a % j == 0)
                            {
                                a = a / j;
                                if (a == 1)
                                {
                                    Console.Write("2");
                                }
                                else
                                {
                                    Console.Write("1\n" + (i * j).ToString());
                                }
                                return;
                            }
                        Console.Write("2");
                        return;
                    }
                }
            }
            Console.Write("1\n0");
            return;
        }
    }
}