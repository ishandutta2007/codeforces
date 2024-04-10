N = raw_input()
if N[N.find('.') - 1] == '9':
    print 'GOTO Vasilisa.'
else:
    d = int(N[N.find('.') + 1])
    if d < 5:
        print N[:N.find('.')]
    else:
        print int(N[:N.find('.')]) + 1