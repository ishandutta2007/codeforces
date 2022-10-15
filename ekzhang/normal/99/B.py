def main():
    N = input()
    cups = [input() for _ in xrange(N)]
    
    sofar = []
    for i in cups:
        if i in sofar:
            newcups = sorted(filter(lambda x: x != i, cups))
            if len(newcups) == 2:
                if newcups[0] + newcups[1] == 2*i:
                    print '{0} ml. from cup #{1} to cup #{2}.'.format(i - newcups[0],
                                                                      cups.index(newcups[0]) + 1,
                                                                      cups.index(newcups[1]) + 1)
                    return
            if len(newcups) == 0:
                print 'Exemplary pages.'
                return
            
            print 'Unrecoverable configuration.'
            return

        sofar.append(i)

    # if the program gets this far, all mL's are different
    if len(cups) > 3:
        print 'Unrecoverable configuration.'
    
    elif len(cups) == 3:
        newcups = sorted(cups)
        if newcups[0] + newcups[2] == 2 * newcups[1]:
            print '{0} ml. from cup #{1} to cup #{2}.'.format(newcups[1] - newcups[0],
                                                              cups.index(newcups[0]) + 1,
                                                              cups.index(newcups[2]) + 1)
        else:
            print 'Unrecoverable configuration.'
    
    elif len(cups) == 2:
        if (cups[0] + cups[1]) % 2 == 0:
            if cups[0] > cups[1]:
                print '{0} ml. from cup #2 to cup #1.'.format((cups[0] - cups[1]) / 2)
            else:
                print '{0} ml. from cup #1 to cup #2.'.format((cups[1] - cups[0]) / 2)
        else:
            print 'Unrecoverable configuration.'
    
    elif len(cups) == 1:
        print 'Exemplary pages.'

if __name__ == '__main__':
    main()